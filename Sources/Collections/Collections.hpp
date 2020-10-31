#ifndef COLLECTIONS_HPP_
#define COLLECTIONS_HPP_

#include "Window.hpp"
#include "ThreadBoard.hpp"
#include "Board.hpp"
#include "FileLoader.hpp"

namespace vgtu::collections {
    class Collections {
        public:
            ~Collections() = default;
            Collections(std::shared_ptr<vgtu::engine::Window> &, std::shared_ptr<vgtu::engine::Event> &);
            Collections(const Collections &) = delete;
            Collections &operator=(const Collections &) = delete;

            void produce();
            void addThread();
            void removeThread();

            void catchEvent();
            void run();
            void draw();            
        private:
            unsigned short int _runningThreadNb;

            std::shared_ptr<vgtu::engine::Window> _window;
            std::shared_ptr<vgtu::engine::Event> _event;
            std::unique_ptr<vgtu::collections::ThreadBoard> _threadBoard;
            std::shared_ptr<vgtu::collections::Board> _board;
            std::unique_ptr<vgtu::collections::FileLoader> _fileLoader;
            std::vector<std::pair<std::string, std::vector<unsigned long long int>>> _producer;
    };
}

#endif