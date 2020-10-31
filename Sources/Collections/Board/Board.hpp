#ifndef BOARD_HPP_
#define BOARD_HPP_

#include <memory>
#include <atomic>
#include "Window.hpp"
#include "Text.hpp"
#include "RectangleShape.hpp"

namespace vgtu::collections {

    class Board {
    public:
        ~Board() = default;
        Board();
        Board(const Board &) = delete;
        Board &operator=(const Board &) = delete;


        void onEvent(std::shared_ptr<vgtu::engine::Window> &, std::shared_ptr<vgtu::engine::Event> &);
        void draw(std::shared_ptr<vgtu::engine::Window> &);

        std::atomic<std::size_t> _ftotal;
        std::atomic<unsigned long long int> _pmin;
        std::atomic<unsigned long long int> _pmax;
        std::atomic<char *> _lfile;
    private:
        std::pair<std::unique_ptr<vgtu::engine::Text>, std::unique_ptr<vgtu::engine::Text>> _min;
        std::pair<std::unique_ptr<vgtu::engine::Text>, std::unique_ptr<vgtu::engine::Text>> _max;
        std::pair<std::unique_ptr<vgtu::engine::Text>, std::unique_ptr<vgtu::engine::Text>> _last;
        std::pair<std::unique_ptr<vgtu::engine::Text>, std::unique_ptr<vgtu::engine::Text>> _total;
        std::unique_ptr<vgtu::engine::shape::RectangleShape> _hr;

    };
}

#endif