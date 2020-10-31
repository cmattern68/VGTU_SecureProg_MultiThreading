#ifndef COLLECTIONS_HPP_
#define COLLECTIONS_HPP_

#include "Window.hpp"
#include "ThreadBoard.hpp"
#include "Board.hpp"

namespace vgtu::collections {
    class Collections {
        public:
            ~Collections() = default;
            Collections(std::shared_ptr<vgtu::engine::Window> &, std::shared_ptr<vgtu::engine::Event> &);
            Collections(const Collections &) = delete;
            Collections &operator=(const Collections &) = delete;

            void catchEvent();
            void run();
            void draw();            
        private:
            std::shared_ptr<vgtu::engine::Window> _window;
            std::shared_ptr<vgtu::engine::Event> _event;
            std::unique_ptr<vgtu::collections::ThreadBoard> _threadBoard;
            std::unique_ptr<vgtu::collections::Board> _board;
    };
}

#endif