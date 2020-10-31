#ifndef ASHAPE_HPP_
#define ASHAPE_HPP_

#include <tuple>

namespace vgtu::engine {

    class AShape {

        public:
            AShape() = default;            
            AShape(const AShape &) = delete;
            ~AShape() = default;            

            std::pair<std::size_t, std::size_t> getPos() { return std::make_pair(_position.x, _position.y); };

        protected:
            unsigned short int _type;
            sf::Vector2f _position;
            std::tuple<unsigned short int, unsigned short int, unsigned short int> _color;
    };
}

#endif