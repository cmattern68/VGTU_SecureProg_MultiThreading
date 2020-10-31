#ifndef EVENT_HPP_
#define EVENT_HPP_

#include <SFML/Graphics.hpp>
#include <memory>

namespace vgtu::engine {

    enum EEvent {
        Closed = sf::Event::Closed,
        LeftClick = sf::Mouse::Left,
    };

    class Event {

        public:
            Event();
            Event(const Event &) = delete;
            ~Event() = default;
            sf::Event &getEvent() { return _event; };
            std::size_t getType() { return _event.type; }
            static std::pair<std::size_t, std::size_t> getMousePosition(std::pair<std::size_t, std::size_t>);            
            bool isMouseReleasedEvent(EEvent);
            bool isMousePressedEvent(EEvent);
                
        private:
            sf::Event _event;
    };
}

#endif