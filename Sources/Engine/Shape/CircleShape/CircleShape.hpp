#ifndef CIRCLESHAPE_HPP_
#define CIRCLESHAPE_HPP_

#include <SFML/Graphics.hpp>
#include "AShape.hpp"

namespace vgtu::engine::shape {

    class CircleShape : public AShape {

        public:
            CircleShape();
            CircleShape(std::pair<std::size_t, std::size_t> , float, std::tuple<unsigned short int, unsigned short int, unsigned short int>);
            CircleShape(const AShape &) = delete;
            ~CircleShape() = default;

            void setPos(std::pair<std::size_t, std::size_t>);

            float getSize() { return _size; };
            void setSize(float);

            sf::CircleShape getShape() { return _circleShape; };
        private:
            float _size;
            sf::CircleShape _circleShape;
    };
}

#endif