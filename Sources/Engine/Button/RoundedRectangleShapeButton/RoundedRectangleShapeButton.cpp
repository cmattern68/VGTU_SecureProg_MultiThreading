#include "RoundedRectangleShapeButton.hpp"
#include <iostream>

namespace vgtu::engine::button {
    RoundedRectangleShapeButton::RoundedRectangleShapeButton(
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
        _shape = std::make_unique<vgtu::engine::shape::RoundedRectangleShape>(
            _pos,
            _size,
            _color,
            5.0
        );        
        _text = std::make_unique<vgtu::engine::Text>(
            std::make_pair(_pos.first + 10, _pos.second + 8),
            std::make_tuple(255, 255, 255),
            25,
            str,
            "Resources/Font/OpenSans.ttf",
            vgtu::engine::textStyle::BOLD
        );
    }

    void RoundedRectangleShapeButton::setBackground(std::tuple<unsigned short int, unsigned short int, unsigned short int> color) {        
        _shape->setBackground(color);
    }

    void RoundedRectangleShapeButton::setPos(std::pair<std::size_t, std::size_t> pos) {
        _pos = pos;
        _shape->setPos({_pos.first, _pos.first});
    }

    void RoundedRectangleShapeButton::setBorder(std::size_t size, std::tuple<unsigned short int, unsigned short int, unsigned short int> color) {
        _shape->setBorder(size, color);
    }

    bool RoundedRectangleShapeButton::isHovered(std::pair<std::size_t, std::size_t> mousePos) {        
        if (mousePos.first >= _pos.first && mousePos.first <= _pos.first + _size.first)
            if (mousePos.second >= _pos.second && mousePos.second <= _pos.second + _size.second)
                return true;
        return false;
    }

    bool RoundedRectangleShapeButton::isClicked(std::shared_ptr<vgtu::engine::Window> &window, std::shared_ptr<vgtu::engine::Event> &evt) {
        if (evt->isMouseReleasedEvent(vgtu::engine::LeftClick) && _isClickable)
            if (isHovered(vgtu::engine::Event::getMousePosition(window->getPosition())))
                return true;            
        return false;
    }

    void RoundedRectangleShapeButton::draw(std::shared_ptr<vgtu::engine::Window> &window) {
        window->draw(_shape->getShape());
        window->draw(_text->getText());
    }
}