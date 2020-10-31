#include "Texture.hpp"
#include "Errors.hpp"

namespace vgtu::engine {

    Texture::Texture(const std::string &path,
                    std::pair<std::size_t, std::size_t> pos,
                    Rect rect,
                    std::pair<float, float> scale) {
        if (!_texture.loadFromFile(path))
            throw RuntimeError {"Unable to load sprite: '" + path + "'."};
        _sprite.setTexture(_texture);
        _pos = pos;
        _rect = {rect.rectLeft, rect.rectTop, rect.rectWidth, rect.rectHeight};
        _scale = {scale.first, scale.second};
        _sprite.setPosition(_pos.first, _pos.second);
        _sprite.setTextureRect(_rect);
        _sprite.setScale({_scale.first, _scale.second});
    }

    void Texture::setPos(std::pair<std::size_t, std::size_t> pos) {
        _pos = pos;
        _sprite.setPosition(_pos.first, _pos.second);
    }

    void Texture::setRect(Rect rect) {
        _rect = {rect.rectLeft, rect.rectTop, rect.rectWidth, rect.rectHeight};
        _sprite.setTextureRect(_rect);
    }

    void Texture::setScale(std::pair<float, float> scale) {
        _scale = {scale.first, scale.second};
        _sprite.setScale({_scale.first, _scale.second});
    }
}