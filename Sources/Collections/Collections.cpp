#include "Collections.hpp"
#include <iostream>
#include <functional>

namespace vgtu::collections
{
    Collections::Collections(std::shared_ptr<vgtu::engine::Window> &window, std::shared_ptr<vgtu::engine::Event> &event) {
        _runningThreadNb = 0;
        _producer = std::array<const char *, 1000>{NULL};
        _consumer = std::array<const char *, 1000>{NULL};

        _board = std::make_shared<vgtu::collections::Board>();
        _window = window;        
        _event = event;
        _threadBoard = std::make_unique<vgtu::collections::ThreadBoard>();
        _producer = FileLoader::getFilesName();
    }

    void Collections::catchEvent() {
        if (_event->getType() == vgtu::engine::Closed)
            _window->close();
        switch(_threadBoard->onEvent(_window, _event)) {
            case threadEvent::ADD:
                addThread();
                break;
            case threadEvent::REMOVE:
                removeThread();
                break;
            default:
                break;
        }
    }

    void Collections::addThread() {
        _threads.push_back(std::make_unique<vgtu::collections::Thread>(std::ref(_producer), std::ref(_consumer), std::ref(_board->_pmin), std::ref(_board->_pmax), std::ref(_board->_ftotal), std::ref(_board->_lfile)));
        ++_runningThreadNb;
    }

    void Collections::removeThread() {
        _threads.pop_back();
        --_runningThreadNb;
    }

    void Collections::run() {
        if (_runningThreadNb < _threadBoard->getThreadNb()) {
            addThread();
        } else if (_runningThreadNb > _threadBoard->getThreadNb()) {
            removeThread();
        }
    }

    void Collections::draw() {
        _threadBoard->draw(_window);
        _board->draw(_window);
    }
}