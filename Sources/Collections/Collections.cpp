#include "Collections.hpp"
#include <time.h>
#include <stdlib.h>

namespace vgtu::collections
{
    Collections::Collections(std::shared_ptr<vgtu::engine::Window> &window, std::shared_ptr<vgtu::engine::Event> &event) {
        _window = window;        
        _event = event;
    }

    void Collections::catchEvent() {
        if (_event->getType() == vgtu::engine::Closed)
            _window->close();
    }

    void Collections::run() {
    }

    void Collections::draw() {
    }
}