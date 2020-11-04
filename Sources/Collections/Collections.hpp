#ifndef COLLECTIONS_HPP_
#define COLLECTIONS_HPP_

#include <atomic>
#include <array>
#include "Window.hpp"
#include "ThreadBoard.hpp"
#include "Board.hpp"
#include "FileLoader.hpp"
#include "Thread.hpp"

namespace vgtu::collections {
    class Collections {
        public:
            ~Collections() = default;
            Collections(std::shared_ptr<vgtu::engine::Window> &, std::shared_ptr<vgtu::engine::Event> &);
            Collections(const Collections &) = delete;
            Collections &operator=(const Collections &) = delete;

            void addThread();
            void removeThread();

            void catchEvent();
            void run();
            void draw();            
        private:
            unsigned short int _runningThreadNb;
            bool _isDone;
            std::vector<std::unique_ptr<vgtu::collections::Thread>> _threads;

            std::shared_ptr<vgtu::engine::Window> _window;
            std::shared_ptr<vgtu::engine::Event> _event;
            std::unique_ptr<vgtu::collections::ThreadBoard> _threadBoard;
            std::shared_ptr<vgtu::collections::Board> _board;
            std::unique_ptr<vgtu::engine::Text> _done;
            std::atomic<std::array<const char *, 1000>> _producer;
            std::atomic<std::array<const char *, 1000>> _consumer;
    };
}

#endif