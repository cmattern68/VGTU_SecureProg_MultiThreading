#ifndef IBUTTON_HPP_
#define IBUTTON_HPP_

#include "Window.hpp"

namespace vgtu::engine {

    class IButton {
        public:
            virtual void setBorder(std::size_t, std::tuple<unsigned short int, unsigned short int, unsigned short int>) = 0;
            virtual void setBackground(std::tuple<unsigned short int, unsigned short int, unsigned short int>) = 0;
            virtual void setPos(std::pair<std::size_t, std::size_t>) = 0;
            virtual std::pair<std::size_t, std::size_t> getPos() = 0;
            virtual void draw(std::shared_ptr<vgtu::engine::Window> &) = 0;

            /* Callback function */            
            virtual bool isHovered(std::pair<std::size_t, std::size_t>) = 0;
            virtual bool isClicked(std::shared_ptr<vgtu::engine::Window> &, std::shared_ptr<vgtu::engine::Event> &) = 0;
            virtual bool isClickable() = 0;
    };
}

#endif