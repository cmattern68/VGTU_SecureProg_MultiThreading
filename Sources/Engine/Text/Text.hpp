#ifndef TEXT_HPP
#define TEXT_HPP

#include <utility>
#include <string>
#include <tuple>
#include <SFML/Graphics.hpp>

namespace vgtu::engine {

    enum textStyle {
        REGULAR = sf::Text::Regular,
        BOLD = sf::Text::Bold,
        ITALIC = sf::Text::Italic,
        UNDERLINED = sf::Text::Underlined
    };

    class Text {
        public:
            Text(std::pair<std::size_t, std::size_t>, std::tuple<unsigned short int, unsigned short int, unsigned short int>, std::size_t, std::string, std::string, textStyle);
            Text(const Text &) = delete;
            ~Text() = default;

            std::pair<std::size_t, std::size_t> getPos() { return _pos; };
            std::tuple<unsigned short int, unsigned short int, unsigned short int> getColor() { return _color; };
            std::size_t getSize() { return _size; };
            std::string getContent() { return _content; };       
            sf::Text getText() { return _text; };

            void setText(std::string);
            void setPos(std::pair<std::size_t, std::size_t>);
            void setColor(std::tuple<unsigned short int, unsigned short int, unsigned short int>);
            void setSize(std::size_t);
            void setContent(std::string);
            void setStyle(textStyle);

        private:
            std::pair<std::size_t, std::size_t> _pos;
            std::tuple<unsigned short int, unsigned short int, unsigned short int> _color;
            std::size_t _size;
            std::string _content;
            sf::Font _font;
            textStyle _style;

            sf::Text _text;
    };
}

#endif