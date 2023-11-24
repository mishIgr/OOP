//
// Created by mikhail on 20.11.23.
//

#ifndef PROJECT_SFML_CHANGE_KEY_MENU_H
#define PROJECT_SFML_CHANGE_KEY_MENU_H

#include "menu.h"
#include "window.h"
#include "sfml_config_scheme.h"
#include "SFML/Graphics.hpp"

template<typename Window>
class SFMLChangeKeyMenu {

    IWindow<Window>* window;
    InReader* reader;

public:

    SFMLChangeKeyMenu(IWindow<Window>*, InReader*);

    void reset(Commands);

};

template<typename Window>
SFMLChangeKeyMenu<Window>::SFMLChangeKeyMenu(IWindow<Window>* window, InReader* reader) : window(window), reader(reader) {}

template<typename Window>
void SFMLChangeKeyMenu<Window>::reset(Commands com) {
    if (this->reader == nullptr || this->window == nullptr)
        return;

    while (this->window->get_window().isOpen()) {
        sf::Event event;

        while (this->window->get_window().pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                this->window->get_window().close();
            if (event.type == sf::Event::KeyPressed) {
                sf::Keyboard::Key tmp = event.key.code;
                if (Keyboard().key_valid(tmp)) {
                    SFMLConfigScheme config_scheme(true);
                    config_scheme.replace_key(tmp, com);
                    config_scheme.save();
                    return;
                }
            }
        }

        this->window->get_window().clear();

        DrawText(this->window, {"Set the key, click key"},
                 "/home/mikhail/OOP_lab/project/font/Nunito/Nunito-VariableFont_wght.ttf", 25, -1);

        this->window->get_window().display();
    }
}

#endif //PROJECT_SFML_CHANGE_KEY_MENU_H
