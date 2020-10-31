#include "Text.hpp"
#include "Errors.hpp"

namespace vgtu::engine {
    Text::Text(
        std::pair<std::size_t, std::size_t> pos,
        std::tuple<unsigned short int, unsigned short int, unsigned short int> color,
        std::size_t size,
        std::string text,
        std::string fontPath,
        textStyle style
    ) {        
        _pos = pos;
        _color = color;
        _size = size;
        _content = text;
        if (!_font.loadFromFile(fontPath))
            throw RuntimeError {"Unable to load font: '" + fontPath + "'."};
        _style = style;

        _text.setPosition({(float)_pos.first, (float)_pos.second});
        _text.setFillColor(sf::Color(std::get<0>(_color), std::get<1>(_color), std::get<2>(_color)));
        _text.setCharacterSize(_size);
        _text.setString(_content);
        _text.setFont(_font);
        _text.setStyle(_style);
    }

    void Text::setText(std::string text) {
        _text.setString(text);
    }

    void Text::setPos(std::pair<std::size_t, std::size_t> pos) {
        _pos = pos;
        _text.setPosition({(float)_pos.first, (float)_pos.second});
    }

    void Text::setColor(std::tuple<unsigned short int, unsigned short int, unsigned short int> color) {
        _color = color;
        _text.setFillColor(sf::Color(std::get<0>(_color), std::get<1>(_color), std::get<2>(_color)));
    }

    void Text::setSize(std::size_t size) {
        _size = size;
        _text.setCharacterSize(_size);
    }

    void Text::setContent(std::string str) {
        _content = str;
        _text.setString(_content);
    }

    void Text::setStyle(textStyle style) {
        _style = style;
        _text.setStyle(_style);
    }
}