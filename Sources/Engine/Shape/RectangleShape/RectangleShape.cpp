#include "RectangleShape.hpp"

namespace vgtu::engine::shape {

    RectangleShape::RectangleShape(std::pair<std::size_t, std::size_t> pos, 
                                   std::pair<std::size_t, std::size_t> size) {
        _position = {(float)pos.first, (float)pos.second};
        _size = {(float)size.first, (float)size.second};        
        sf::RectangleShape rectangle(_size);
        _rectangleShape = rectangle;
        _rectangleShape.setPosition(_position);        
    }

    RectangleShape::RectangleShape(std::pair<std::size_t, std::size_t> pos, 
                                   std::pair<std::size_t, std::size_t> size,
                                   std::tuple<unsigned short int, unsigned short int, unsigned short int> color) {        
        _position = {(float)pos.first, (float)pos.second};
        _size = {(float)size.first, (float)size.second};
        _color = color;
        sf::RectangleShape rectangle(_size);
        _rectangleShape = rectangle;
        _rectangleShape.setPosition(_position);
        _rectangleShape.setFillColor(sf::Color(std::get<0>(_color), std::get<1>(_color), std::get<2>(_color)));
    }

    void RectangleShape::setPos(std::pair<std::size_t, std::size_t> pos) {
        _position = { (float)pos.first, (float)pos.second };
        _rectangleShape.setPosition(_position);
    }

    void RectangleShape::setSize(std::pair<std::size_t, std::size_t> size) {
        _size = {(float)size.first, (float)size.second};
        _rectangleShape.setSize(_size);
    }

    void RectangleShape::setBorder(std::size_t size, std::tuple<unsigned short int, unsigned short int, unsigned short int> color) {
        _rectangleShape.setOutlineThickness(size);
        _rectangleShape.setOutlineColor(sf::Color(std::get<0>(color), std::get<1>(color), std::get<2>(color)));
    }

    void RectangleShape::setBackground(std::tuple<unsigned short int, unsigned short int, unsigned short int> color) {
        _rectangleShape.setFillColor(sf::Color(std::get<0>(color), std::get<1>(color), std::get<2>(color)));
        _color = color;
    }
}