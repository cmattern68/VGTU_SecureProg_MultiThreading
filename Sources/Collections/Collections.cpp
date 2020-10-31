#include "Collections.hpp"
#include <iostream>

namespace vgtu::collections
{
    Collections::Collections(std::shared_ptr<vgtu::engine::Window> &window, std::shared_ptr<vgtu::engine::Event> &event) {
        _runningThreadNb = 1;

        _window = window;        
        _event = event;
        _threadBoard = std::make_unique<vgtu::collections::ThreadBoard>();
        _board = std::make_shared<vgtu::collections::Board>();
        _fileLoader = std::make_unique<vgtu::collections::FileLoader>();
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

    void Collections::produce() {
        _producer = _fileLoader->loadBulkContent();
    }

    void Collections::addThread() {
        ++_runningThreadNb;
        std::cout << "1 thread added." << std::endl;
    }

    void Collections::removeThread() {
        --_runningThreadNb;
        std::cout << "1 thread removed." << std::endl;
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