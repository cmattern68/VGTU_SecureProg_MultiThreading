#include "Collections.hpp"
#include <time.h>
#include <stdlib.h>

namespace vgtu::collections
{
    Collections::Collections(std::shared_ptr<vgtu::engine::Window> &window, std::shared_ptr<vgtu::engine::Event> &event) {
        _window = window;        
        _event = event;
        _threadBoard = std::make_unique<vgtu::collections::ThreadBoard>();
        _board = std::make_shared<vgtu::collections::Board>();
    }

    void Collections::catchEvent() {
        if (_event->getType() == vgtu::engine::Closed)
            _window->close();
        _threadBoard->onEvent(_window, _event);
    }

    void Collections::run() {
    }

    void Collections::draw() {
        _threadBoard->draw(_window);
        _board->draw(_window);
    }
}