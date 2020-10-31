#ifndef BOARD_HPP_
#define BOARD_HPP_

#include <memory>
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

        void setPrime(const unsigned long long int);
        void setLast(const std::string);
        void updateTotal();

        void onEvent(std::shared_ptr<vgtu::engine::Window> &, std::shared_ptr<vgtu::engine::Event> &);
        void draw(std::shared_ptr<vgtu::engine::Window> &);
    private:
        std::size_t _ftotal;
        unsigned long long int _pmin;
        unsigned long long int _pmax;
        std::pair<std::unique_ptr<vgtu::engine::Text>, std::unique_ptr<vgtu::engine::Text>> _min;
        std::pair<std::unique_ptr<vgtu::engine::Text>, std::unique_ptr<vgtu::engine::Text>> _max;
        std::pair<std::unique_ptr<vgtu::engine::Text>, std::unique_ptr<vgtu::engine::Text>> _last;
        std::pair<std::unique_ptr<vgtu::engine::Text>, std::unique_ptr<vgtu::engine::Text>> _total;
        std::unique_ptr<vgtu::engine::shape::RectangleShape> _hr;

    };
}

#endif