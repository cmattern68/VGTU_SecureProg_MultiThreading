#ifndef WINDOW_HPP
#define WINDOW_HPP

#include <utility>
#include <string>
#include <SFML/Graphics.hpp>
#include <memory>
#include <tuple>
#include "Event.hpp"

namespace vgtu::engine {
    class Window {
        public:
            Window(std::pair<std::size_t, std::size_t>, std::string);
            Window(const Window &) = delete;
            ~Window() = default;            
            
            void setSize(std::pair<std::size_t, std::size_t>);
            const std::pair<std::size_t, std::size_t> getSize() { return std::make_pair(_window.getSize().x, _window.getSize().y);; };

            void setTitle(const std::string &);
            const std::string getTitle() { return _name; };            

            std::pair<std::size_t, std::size_t> getPosition();

            bool isOpen() { return _window.isOpen(); }
            bool pollEvent(Event *evt) { return _window.pollEvent(evt->getEvent()); }
            void close() { _window.close(); }
            void clear(std::tuple<unsigned short int, unsigned short int, unsigned short int> color) { _window.clear(sf::Color(std::get<0>(color), std::get<1>(color), std::get<2>(color))); };
            void draw(const sf::Drawable &drawable);
            void display() { _window.display(); };
        
        private:
            std::pair<std::size_t, std::size_t> _size;
            std::string _name;
            sf::RenderWindow _window;
    };
}

#endif