#ifndef THREADBOARD_HPP_
#define THREADBOARD_HPP_

#include <memory>
#include "Window.hpp"
#include "Text.hpp"
#include "SpriteButton.hpp"
#include "RectangleShape.hpp"

namespace vgtu::collections {

    class ThreadBoard {
    public:
        ~ThreadBoard() = default;
        ThreadBoard();
        ThreadBoard(const ThreadBoard &) = delete;
        ThreadBoard &operator=(const ThreadBoard &) = delete;

        unsigned short int getThreadNb() const { return _threadNb; }

        void onEvent(std::shared_ptr<vgtu::engine::Window> &, std::shared_ptr<vgtu::engine::Event> &);
        void draw(std::shared_ptr<vgtu::engine::Window> &);
    private:
        void addThread();
        void removeThread();

        unsigned short int _threadNb;
        std::unique_ptr<vgtu::engine::Text> _sentence;
        std::unique_ptr<vgtu::engine::Text> _thread;
        std::unique_ptr<vgtu::engine::IButton> _mButton;
        std::unique_ptr<vgtu::engine::IButton> _pButton;
        std::unique_ptr<vgtu::engine::shape::RectangleShape> _hr;
    };
}

#endif