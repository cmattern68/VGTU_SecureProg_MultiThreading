#include "RectangleShapeButton.hpp"
#include <iostream>

namespace vgtu::engine::button {
    RectangleShapeButton::RectangleShapeButton(
        std::pair<std::size_t, std::size_t> pos,
        std::pair<std::size_t, std::size_t> size,
        std::tuple<unsigned short int, unsigned short int, unsigned short int> color,
        std::string str,
        bool isClickable
    ) {
        _isClickable = isClickable;
        _pos = pos;
        _size = size;
        _color = color;
        _shape = std::make_unique<vgtu::engine::shape::RectangleShape>(
            _pos,
            _size,
            _color
        );        
        _text = std::make_unique<vgtu::engine::Text>(
            std::make_pair(_pos.first + 10, _pos.second + 5),
            std::make_tuple(255, 255, 255),
            20,
            str,
            "Resources/Font/OpenSans.ttf",
            vgtu::engine::textStyle::REGULAR
        );
    }

    void RectangleShapeButton::setBackground(std::tuple<unsigned short int, unsigned short int, unsigned short int> color) {        
        _shape->setBackground(color);
    }

    void RectangleShapeButton::setPos(std::pair<std::size_t, std::size_t> pos) {
        _pos = pos;
        _shape->setPos({_pos.first, _pos.first});
    }

    void RectangleShapeButton::setBorder(std::size_t size, std::tuple<unsigned short int, unsigned short int, unsigned short int> color) {
        _shape->setBorder(size, color);
    }

    bool RectangleShapeButton::isHovered(std::pair<std::size_t, std::size_t> mousePos) {        
        if (mousePos.first >= _pos.first && mousePos.first <= _pos.first + _size.first)
            if (mousePos.second >= _pos.second && mousePos.second <= _pos.second + _size.second)
                return true;
        return false;
    }

    bool RectangleShapeButton::isClicked(std::shared_ptr<vgtu::engine::Window> &window, std::shared_ptr<vgtu::engine::Event> &evt) {
        if (evt->isMouseReleasedEvent(vgtu::engine::LeftClick) && _isClickable)
            if (isHovered(vgtu::engine::Event::getMousePosition(window->getPosition())))
                return true;            
        return false;
    }

    void RectangleShapeButton::draw(std::shared_ptr<vgtu::engine::Window> &window) {
        window->draw(_shape->getShape());
        window->draw(_text->getText());
    }
}