#ifndef ROUNDEDRECTANGLESHAPE_HPP_
#define ROUNDEDRECTANGLESHAPE_HPP_

#include "SfmlRoundedRectangleShape.hpp"
#include "AShape.hpp"

namespace vgtu::engine::shape {

    class RoundedRectangleShape : public AShape {

        public:
            RoundedRectangleShape(std::pair<std::size_t, std::size_t>, std::pair<std::size_t, std::size_t>, std::tuple<unsigned short int, unsigned short int, unsigned short int>, float);
            RoundedRectangleShape(const AShape &) = delete;
            ~RoundedRectangleShape() = default;

            void setPos(std::pair<std::size_t, std::size_t>);

            void setBackground(std::tuple<unsigned short int, unsigned short int, unsigned short int>);
            std::pair<std::size_t, std::size_t> getSize() { return std::make_pair(_size.x, _size.y); };
            void setSize(std::pair<std::size_t, std::size_t>);

            void setBorder(std::size_t, std::tuple<unsigned short int, unsigned short int, unsigned short int>);

            sf::RoundedRectangleShape getShape() { return _shape; };
        private:
            sf::Vector2f _size;
            sf::RoundedRectangleShape _shape;
    };
}

#endif