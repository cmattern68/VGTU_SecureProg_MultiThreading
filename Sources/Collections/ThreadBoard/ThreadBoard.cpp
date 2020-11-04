#include "ThreadBoard.hpp"
#include <string>
#include <thread>

namespace vgtu::collections
{
    ThreadBoard::ThreadBoard() {
        _threadNb = 1;
        _sentence = std::make_unique<vgtu::engine::Text>(
                std::make_pair(160, 8),
                std::make_tuple(44, 62, 80),
                20,
                std::string("Number of threads running:"),
                "Resources/Font/OpenSans.ttf",
                vgtu::engine::textStyle::BOLD
        );
        _thread = std::make_unique<vgtu::engine::Text>(
                std::make_pair(290, 48),
                std::make_tuple(44, 62, 80),
                38,
                std::to_string(_threadNb),
                "Resources/Font/OpenSans.ttf",
                vgtu::engine::textStyle::BOLD
        );
        _mButton = std::make_unique<vgtu::engine::button::SpriteButton>(
                std::make_pair(160, 50),
                "Resources/Button/minus.png",
                vgtu::engine::Rect {0, 0, 40, 40},
                std::make_pair(1, 1),
                true
        );
        _pButton = std::make_unique<vgtu::engine::button::SpriteButton>(
                std::make_pair(400, 50),
                "Resources/Button/add.png",
                vgtu::engine::Rect {0, 0, 40, 40},
                std::make_pair(1, 1),
                true
        );
        _hr = std::make_unique<vgtu::engine::shape::RectangleShape>(
                std::make_pair(0, 100),
                std::make_pair(600, 2),
                std::make_tuple(44, 62, 80)
        );
    }

    void ThreadBoard::setDone() {
        _threadNb = 0;
        _thread->setText("0");
    }

    void ThreadBoard::addThread() {
        if (_threadNb < 100) {
            if (_threadNb == 9)
                _thread->setPos(std::make_pair(280, 48));
            if (_threadNb == 99)
                _thread->setPos(std::make_pair(265, 48));
            ++_threadNb;
            _thread->setText(std::to_string(_threadNb));
        }
    }

    void ThreadBoard::removeThread() {
        if (_threadNb > 1) {
            if (_threadNb == 10)
                _thread->setPos(std::make_pair(290, 48));
            if (_threadNb == 100)
                _thread->setPos(std::make_pair(280, 48));
            --_threadNb;
            _thread->setText(std::to_string(_threadNb));
        }
    }

    threadEvent ThreadBoard::onEvent(std::shared_ptr<vgtu::engine::Window> &window, std::shared_ptr<vgtu::engine::Event> &evt) {
        if (_threadNb > 1) {
            if (_mButton->isClicked(window, evt)) {
                removeThread();
                return threadEvent::REMOVE;
            }
        }
        if (_threadNb < 100) {
            if (_pButton->isClicked(window, evt)) {
                addThread();
                return threadEvent::ADD;
            }
        }
        return threadEvent::NONE;
    }

    void ThreadBoard::draw(std::shared_ptr<vgtu::engine::Window> &window) {
        window->draw(_hr->getShape());
        window->draw(_sentence->getText());
        window->draw(_thread->getText());
        if (_threadNb > 1)
            _mButton->draw(window);
        if (_threadNb < 100 && _threadNb > 0)
            _pButton->draw(window);
    }
}