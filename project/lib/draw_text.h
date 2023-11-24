//
// Created by mikhail on 19.11.23.
//

#ifndef PROJECT_DRAW_TEXT_H
#define PROJECT_DRAW_TEXT_H

#include "SFML/Graphics.hpp"
#include "window.h"
#include <vector>

template<typename Window>
class DrawText {
public:

    DrawText(IWindow<Window>*, std::vector<std::string>, std::string, unsigned, unsigned);

};

template<typename Window>
DrawText<Window>::DrawText(IWindow<Window>* window, std::vector<std::string> captions, std::string loc_font, unsigned charecterSize, unsigned marker) {
    sf::Font font;
    font.loadFromFile(loc_font);
    for (size_t i = 0; i < captions.size(); ++i) {
        sf::Text text(captions[i], font, charecterSize);
        text.setPosition((window->get_window().getSize().x - text.getLocalBounds().width) / 2,
                         (window->get_window().getSize().y - charecterSize * captions.size()) / 2 + (charecterSize + 5) * i);
        if (i == marker)
            text.setFillColor(sf::Color::Green);

        window->get_window().draw(text);
    }
}

#endif //PROJECT_DRAW_TEXT_H
