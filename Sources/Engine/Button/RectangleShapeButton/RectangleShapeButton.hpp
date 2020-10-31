#ifndef RECTANGLESHAPEBUTTON_HPP_
#define RECTANGLESHAPEBUTTON_HPP_

#include "RectangleShape.hpp"
#include "Text.hpp"
#include "IButton.hpp"

namespace vgtu::engine::button {

    class RectangleShapeButton : public IButton {
        public:
            ~RectangleShapeButton() = default;
            RectangleShapeButton(std::pair<std::size_t, std::size_t>, std::pair<std::size_t, std::size_t>, std::tuple<unsigned short int, unsigned short int, unsigned short int>, std::string, bool);
            RectangleShapeButton(const RectangleShapeButton &) = delete;
            RectangleShapeButton &operator=(const RectangleShapeButton &) = delete;

            void setPos(std::pair<std::size_t, std::size_t>) override final;
            std::pair<std::size_t, std::size_t> getPos() override final { return _pos; };

            void setBackground(std::tuple<unsigned short int, unsigned short int, unsigned short int>);
            void setBorder(std::size_t, std::tuple<unsigned short int, unsigned short int, unsigned short int>);

            void draw(std::shared_ptr<vgtu::engine::Window> &) override final;

            /* Callback function */            
            bool isHovered(std::pair<std::size_t, std::size_t>) override final;
            bool isClicked(std::shared_ptr<vgtu::engine::Window> &, std::shared_ptr<vgtu::engine::Event> &) override final;
            bool isClickable() override final { return _isClickable; };
        private:
            bool _isClickable;
            std::pair<std::size_t, std::size_t> _pos;
            std::pair<std::size_t, std::size_t> _size;
            std::tuple<unsigned short int, unsigned short int, unsigned short int> _color;
            std::unique_ptr<vgtu::engine::shape::RectangleShape> _shape;
            std::unique_ptr<vgtu::engine::Text> _text;

    };
}

#endif