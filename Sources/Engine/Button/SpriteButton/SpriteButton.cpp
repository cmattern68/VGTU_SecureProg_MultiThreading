#include "SpriteButton.hpp"

namespace vgtu::engine::button {
    SpriteButton::SpriteButton(
        std::pair<std::size_t, std::size_t> pos,
        std::string path,
        Rect rect,
        std::pair<float, float> scale,
        bool isClickable
    ) {
        _isClickable = isClickable;
        _pos = pos;        
        _texture = std::make_unique<Texture>(
            path,
            std::make_pair(_pos.first, _pos.second),
            rect,
            scale
        );
    }

    void SpriteButton::setPos(std::pair<std::size_t, std::size_t> pos) {
        _pos = pos;
        _texture->setPos({_pos.first, _pos.first});
    }

    bool SpriteButton::isHovered(std::pair<std::size_t, std::size_t> mousePos, std::pair<std::size_t, std::size_t> windowPos) {
        if ((mousePos.first + windowPos.first) >= (_pos.first + windowPos.first) && (mousePos.first + windowPos.first) <= (_pos.first + _texture->getRect().rectWidth + windowPos.first)) {
            if ((mousePos.second + _texture->getRect().rectHeight) >= (_pos.second + windowPos.second) && (mousePos.second + _texture->getRect().rectHeight) <= (_pos.second + _texture->getRect().rectHeight + windowPos.second)) {
                return true;
            }
        }                        
        return false;
    }

    bool SpriteButton::isClicked(std::shared_ptr<vgtu::engine::Window> &window, std::shared_ptr<vgtu::engine::Event> &evt) {
        if (evt->isMouseReleasedEvent(vgtu::engine::LeftClick))
            if (isHovered(vgtu::engine::Event::getMousePosition(window->getPosition()), window->getPosition()))
                return true;
        return false;
    }

    void SpriteButton::draw(std::shared_ptr<vgtu::engine::Window> &window) {
        window->draw(_texture->getSprite());
    }
}