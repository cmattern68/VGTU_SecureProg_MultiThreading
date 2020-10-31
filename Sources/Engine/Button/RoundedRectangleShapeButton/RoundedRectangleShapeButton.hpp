#ifndef ROUNDEDRECTANGLESHAPEBUTTON_HPP_
#define ROUNDEDRECTANGLESHAPEBUTTON_HPP_

#include "RoundedRectangleShape.hpp"
#include "Text.hpp"
#include "IButton.hpp"

namespace vgtu::engine::button {

    class RoundedRectangleShapeButton : public IButton {
        public:
            ~RoundedRectangleShapeButton() = default;
            RoundedRectangleShapeButton(std::pair<std::size_t, std::size_t>, std::pair<std::size_t, std::size_t>, std::tuple<unsigned short int, unsigned short int, unsigned short int>, std::string, bool);
            RoundedRectangleShapeButton(const RoundedRectangleShapeButton &) = delete;
            RoundedRectangleShapeButton &operator=(const RoundedRectangleShapeButton &) = delete;

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
            std::unique_ptr<vgtu::engine::shape::RoundedRectangleShape> _shape;
            std::unique_ptr<vgtu::engine::Text> _text;
            std::tuple<unsigned short int, unsigned short int, unsigned short int> _color;

    };
}

#endif