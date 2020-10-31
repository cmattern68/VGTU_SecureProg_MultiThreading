#include "Window.hpp"

namespace vgtu::engine {
    Window::Window(std::pair<std::size_t, std::size_t> size, std::string name) {
        _size = size;
        _name = name;
        _window.create(sf::VideoMode(_size.first, _size.second), _name.c_str(), sf::Style::Close);
        _window.setVerticalSyncEnabled(true);
        _size = std::make_pair(_window.getSize().x, _window.getSize().y);
    }

    void Window::setSize(std::pair<std::size_t, std::size_t> size) {
        _size = size;
        _window.setSize(sf::Vector2u(_size.first, _size.second));
        _size = std::make_pair(_window.getSize().x, _window.getSize().y);
    }

    void Window::setTitle(const std::string &name) {
        _name = name;
        _window.setTitle(_name.c_str());
    }

    std::pair<std::size_t, std::size_t> Window::getPosition() {
        return std::make_pair(_window.getPosition().x, _window.getPosition().y);
    }

    void Window::draw(const sf::Drawable &drawable) {
        _window.draw(drawable);
    }    
}