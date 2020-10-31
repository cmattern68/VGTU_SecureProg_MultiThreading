#include "Collections.hpp"

namespace vgtu::collections
{
    Collections::Collections(std::shared_ptr<vgtu::engine::Window> &window, std::shared_ptr<vgtu::engine::Event> &event) {
        _window = window;        
        _event = event;
        _threadBoard = std::make_unique<vgtu::collections::ThreadBoard>();
        _board = std::make_shared<vgtu::collections::Board>();
        _fileLoader = std::make_unique<vgtu::collections::FileLoader>();
    }

    void Collections::catchEvent() {
        if (_event->getType() == vgtu::engine::Closed)
            _window->close();
        _threadBoard->onEvent(_window, _event);
    }

    void Collections::produce() {
        _producer = _fileLoader->loadBulkContent();
    }

    void Collections::run() {
    }

    void Collections::draw() {
        _threadBoard->draw(_window);
        _board->draw(_window);
    }
}