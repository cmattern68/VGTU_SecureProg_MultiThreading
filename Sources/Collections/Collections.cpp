#include "Collections.hpp"
#include <functional>

namespace vgtu::collections
{
    Collections::Collections(std::shared_ptr<vgtu::engine::Window> &window, std::shared_ptr<vgtu::engine::Event> &event) {
        _runningThreadNb = 0;
        _isDone = false;
        _producer = std::array<const char *, 1000>{NULL};
        _consumer = std::array<const char *, 1000>{NULL};

        _board = std::make_shared<vgtu::collections::Board>();
        _window = window;        
        _event = event;
        _threadBoard = std::make_unique<vgtu::collections::ThreadBoard>();
        _producer = FileLoader::getFilesName();

        _done = std::make_unique<vgtu::engine::Text>(
                std::make_pair(230, 207),
                std::make_tuple(230, 126, 34),
                25,
                std::string("In progress..."),
                "Resources/Font/OpenSans.ttf",
                vgtu::engine::textStyle::REGULAR
                );
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
        ++_runningThreadNb;
        _threads.push_back(std::make_unique<vgtu::collections::Thread>(std::ref(_producer),
                                                                       std::ref(_consumer),
                                                                       std::ref(_board->_pmin),
                                                                       std::ref(_board->_pmax),
                                                                       std::ref(_board->_ftotal),
                                                                       std::ref(_board->_lfile),
                                                                       _runningThreadNb));
    }

    void Collections::removeThread() {
        _threads.pop_back();
        --_runningThreadNb;
    }

    void Collections::run() {
        if (_board->_ftotal < 1000) {
            if (_runningThreadNb < _threadBoard->getThreadNb()) {
                addThread();
            } else if (_runningThreadNb > _threadBoard->getThreadNb()) {
                removeThread();
            }
        } else if (_board->_ftotal == 1000 && !_isDone) {
            _isDone = true;
            _done->setPos(std::make_pair(260, 207));
            _done->setText("Done !");
            _done->setColor(std::make_tuple(39, 174, 96));
            _threads.clear();
            _threadBoard->setDone();
        }
    }

    void Collections::draw() {
        _threadBoard->draw(_window);
        _board->draw(_window);
        _window->draw(_done->getText());
    }
}