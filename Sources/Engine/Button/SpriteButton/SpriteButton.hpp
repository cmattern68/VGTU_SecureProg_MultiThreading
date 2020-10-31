#ifndef SPRITEBUTTON_HPP_
#define SPRITEBUTTON_HPP_

#include "Texture.hpp"
#include "IButton.hpp"

namespace vgtu::engine::button {

    class SpriteButton : public IButton {
        public:
            ~SpriteButton() = default;
            SpriteButton(std::pair<std::size_t, std::size_t>, std::string, Rect , std::pair<float, float>, bool);
            SpriteButton(const SpriteButton &) = delete;
            SpriteButton &operator=(const SpriteButton &) = delete;

            void setBackground(std::tuple<unsigned short int, unsigned short int, unsigned short int>) {};
            void setBorder(std::size_t, std::tuple<unsigned short int, unsigned short int, unsigned short int>) override final {};
            void setPos(std::pair<std::size_t, std::size_t>) override final;
            std::pair<std::size_t, std::size_t> getPos() override final { return _pos; };

            void draw(std::shared_ptr<vgtu::engine::Window> &) override final;

            /* Callback function */            
            bool isHovered(std::pair<std::size_t, std::size_t>, std::pair<std::size_t, std::size_t>) override final;
            bool isClicked(std::shared_ptr<vgtu::engine::Window> &, std::shared_ptr<vgtu::engine::Event> &) override final;
            bool isClickable() override final { return _isClickable; };
        private:
            bool _isClickable;
            std::pair<std::size_t, std::size_t> _pos;
            std::unique_ptr<Texture> _texture;

    };
}

#endif