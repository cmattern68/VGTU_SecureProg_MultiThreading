#ifndef TEXTURE_HPP_
#define TEXTURE_HPP_

#include <utility>
#include <string>
#include <SFML/Graphics.hpp>

namespace vgtu::engine {
    struct Rect {
        int rectLeft;
        int rectTop;
        int rectWidth;
        int rectHeight; 
    };

    class Texture {
        public:
            Texture() = delete;
            Texture(const std::string &, std::pair<std::size_t, std::size_t>, Rect, std::pair<float, float>);
            Texture(const Texture &) = delete;
            ~Texture() = default;

            sf::Sprite getSprite() { return _sprite; };
            std::pair<std::size_t, std::size_t> getPos() { return _pos; };
            Rect getRect() { return Rect {_rect.left, _rect.top, _rect.width, _rect.height}; };
            std::pair<float, float> getScale() { return _scale; };

            void setPos(std::pair<std::size_t, std::size_t>);
            void setRect(Rect);
            void setScale(std::pair<float, float>);
        private:
            sf::Texture _texture;
            sf::Sprite _sprite;
            sf::IntRect _rect;
            std::pair<std::size_t, std::size_t> _pos;
            std::pair<float, float> _scale;
    };
}

#endif