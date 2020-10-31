#ifndef RECTANGLESHAPE_HPP_
#define RECTANGLESHAPE_HPP_

#include <SFML/Graphics.hpp>
#include "AShape.hpp"

namespace vgtu::engine::shape {

    class RectangleShape : public AShape {

        public:
            RectangleShape();
            RectangleShape(std::pair<std::size_t, std::size_t> , std::pair<std::size_t, std::size_t>);
            RectangleShape(std::pair<std::size_t, std::size_t> , std::pair<std::size_t, std::size_t>, std::tuple<unsigned short int, unsigned short int, unsigned short int>);            
            RectangleShape(const AShape &) = delete;
            ~RectangleShape() = default;

            void setPos(std::pair<std::size_t, std::size_t>);

            std::pair<std::size_t, std::size_t> getSize() { return std::make_pair(_size.x, _size.y); };
            void setSize(std::pair<std::size_t, std::size_t>);

            void setBorder(std::size_t, std::tuple<unsigned short int, unsigned short int, unsigned short int>);
            void setBackground(std::tuple<unsigned short int, unsigned short int, unsigned short int>);

            sf::RectangleShape getShape() { return _rectangleShape; };
        private:
            sf::Vector2f _size;
            sf::RectangleShape _rectangleShape;
    };
}

#endif