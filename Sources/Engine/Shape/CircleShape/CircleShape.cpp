#include "CircleShape.hpp"

namespace vgtu::engine::shape {

    CircleShape::CircleShape(std::pair<std::size_t, std::size_t> pos, 
                                   float radius,
                                   std::tuple<unsigned short int, unsigned short int, unsigned short int> color) {        
        _position = {(float)pos.first, (float)pos.second};
        _size = radius;
        _color = color;
        sf::CircleShape circle(_size);
        _circleShape = circle;
        _circleShape.setPosition(_position);
        _circleShape.setFillColor(sf::Color(std::get<0>(_color), std::get<1>(_color), std::get<2>(_color)));
    }

    void CircleShape::setPos(std::pair<std::size_t, std::size_t> pos) {
        _position = { (float)pos.first, (float)pos.second };
        _circleShape.setPosition(_position);
    }

    void CircleShape::setSize(float radius) {
        _size = radius;
        _circleShape.setRadius(_size);
    }
}