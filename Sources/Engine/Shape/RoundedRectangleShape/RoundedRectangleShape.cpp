#include "RoundedRectangleShape.hpp"

namespace vgtu::engine::shape {

    RoundedRectangleShape::RoundedRectangleShape(std::pair<std::size_t, std::size_t> pos, 
                                   std::pair<std::size_t, std::size_t> size,
                                   std::tuple<unsigned short int, unsigned short int, unsigned short int> color,
                                   float radius) {        
        _position = {(float)pos.first, (float)pos.second};
        _size = {(float)size.first, (float)size.second};
        _color = color;
        sf::RoundedRectangleShape rectangle(_size, radius, 500);
        _shape = rectangle;
        _shape.setPosition(_position);
        _shape.setFillColor(sf::Color(std::get<0>(_color), std::get<1>(_color), std::get<2>(_color)));
    }

    void RoundedRectangleShape::setBackground(std::tuple<unsigned short int, unsigned short int, unsigned short int> color) {
        _color = color;
        _shape.setFillColor(sf::Color(std::get<0>(_color), std::get<1>(_color), std::get<2>(_color)));
    }

    void RoundedRectangleShape::setPos(std::pair<std::size_t, std::size_t> pos) {
        _position = { (float)pos.first, (float)pos.second };
        _shape.setPosition(_position);
    }

    void RoundedRectangleShape::setSize(std::pair<std::size_t, std::size_t> size) {
        _size = {(float)size.first, (float)size.second};
        _shape.setSize(_size);
    }

    void RoundedRectangleShape::setBorder(std::size_t size, std::tuple<unsigned short int, unsigned short int, unsigned short int> color) {        
        _shape.setOutlineThickness(size);
        _shape.setOutlineColor(sf::Color(std::get<0>(color), std::get<1>(color), std::get<2>(color)));
    }
}