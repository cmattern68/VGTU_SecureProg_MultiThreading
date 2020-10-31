#include "Board.hpp"

namespace vgtu::collections
{
    Board::Board() {
        _ftotal = 0;
        _pmin = 0;
        _pmax = 0;
        _min = std::make_pair<std::unique_ptr<vgtu::engine::Text>>(
                std::make_unique<vgtu::engine::Text>(
                    std::make_pair(10, 110),
                    std::make_tuple(44, 62, 80),
                    18,
                    std::string("Minimal prime found:"),
                    "Resources/Font/OpenSans.ttf",
                    vgtu::engine::textStyle::REGULAR
                ),
                std::make_unique<vgtu::engine::Text>(
                    std::make_pair(200, 110),
                    std::make_tuple(44, 62, 80),
                    18,
                    std::string("-"),
                    "Resources/Font/OpenSans.ttf",
                    vgtu::engine::textStyle::REGULAR
                )
        );
        _max = std::make_pair<std::unique_ptr<vgtu::engine::Text>>(
                std::make_unique<vgtu::engine::Text>(
                    std::make_pair(10, 135),
                    std::make_tuple(44, 62, 80),
                    18,
                    std::string("Maximal prime found:"),
                    "Resources/Font/OpenSans.ttf",
                    vgtu::engine::textStyle::REGULAR
                ),
                std::make_unique<vgtu::engine::Text>(
                    std::make_pair(200, 135),
                    std::make_tuple(44, 62, 80),
                    18,
                    std::string("-"),
                    "Resources/Font/OpenSans.ttf",
                    vgtu::engine::textStyle::REGULAR
                )
        );
        _last = std::make_pair<std::unique_ptr<vgtu::engine::Text>>(
                std::make_unique<vgtu::engine::Text>(
                    std::make_pair(10, 155),
                    std::make_tuple(44, 62, 80),
                    18,
                    std::string("Last updating file:"),
                    "Resources/Font/OpenSans.ttf",
                    vgtu::engine::textStyle::REGULAR
                ),
                std::make_unique<vgtu::engine::Text>(
                    std::make_pair(200, 155),
                    std::make_tuple(44, 62, 80),
                    18,
                    std::string("None"),
                    "Resources/Font/OpenSans.ttf",
                    vgtu::engine::textStyle::REGULAR
                )
        );
        _total = std::make_pair<std::unique_ptr<vgtu::engine::Text>>(
                std::make_unique<vgtu::engine::Text>(
                    std::make_pair(10, 175),
                    std::make_tuple(44, 62, 80),
                    18,
                    std::string("File processed:"),
                    "Resources/Font/OpenSans.ttf",
                    vgtu::engine::textStyle::REGULAR
                ),
                std::make_unique<vgtu::engine::Text>(
                    std::make_pair(200, 175),
                    std::make_tuple(44, 62, 80),
                    18,
                    std::string("-"),
                    "Resources/Font/OpenSans.ttf",
                    vgtu::engine::textStyle::REGULAR
                )
        );
        _hr = std::make_unique<vgtu::engine::shape::RectangleShape>(
                std::make_pair(0, 205),
                std::make_pair(600, 2),
                std::make_tuple(44, 62, 80)
        );
    }

    void Board::setPrime(const std::size_t nb) {
        if (nb < _pmin) {
            _pmin = nb;
            _min.second->setText(std::to_string(nb));
        } else if (nb > _pmax) {
            _pmax = nb;
            _max.second->setText(std::to_string(nb));
        }
    }

    void Board::setLast(const std::string path) {
        _last.second->setText(path);
    }

    void Board::updateTotal() {
        ++_ftotal;
        _total.second->setText(std::to_string(_ftotal));
    }

    void Board::onEvent(std::shared_ptr<vgtu::engine::Window> &window, std::shared_ptr<vgtu::engine::Event> &evt) {
        (void)window;
        (void)evt;
    }

    void Board::draw(std::shared_ptr<vgtu::engine::Window> &window) {
        window->draw(_min.first->getText());
        window->draw(_min.second->getText());
        window->draw(_max.first->getText());
        window->draw(_max.second->getText());
        window->draw(_last.first->getText());
        window->draw(_last.second->getText());
        window->draw(_total.first->getText());
        window->draw(_total.second->getText());
        window->draw(_hr->getShape());
    }
}