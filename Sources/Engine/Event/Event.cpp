#include "Event.hpp"

namespace vgtu::engine {
    Event::Event() {
    }

    std::pair<std::size_t, std::size_t> Event::getMousePosition(std::pair<std::size_t, std::size_t> windowPos) {        
        sf::Vector2i pos = sf::Mouse::getPosition();        
        return std::make_pair(pos.x - windowPos.first, pos.y - 57);
    }

    bool Event::isMouseReleasedEvent(EEvent evt) {
        if (_event.type == sf::Event::MouseButtonReleased) {
            if (_event.mouseButton.button == (sf::Mouse::Button)evt) {
                return true;
            }
        }
        return false;
    }

    bool Event::isMousePressedEvent(EEvent evt) {
        if (_event.type == sf::Event::MouseButtonPressed) {
            if (_event.mouseButton.button == (sf::Mouse::Button)evt) {
                return true;
            }
        }
        return false;
    }
}