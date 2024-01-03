//
// Created by mikhail on 27.11.23.
//

#include "Menu/sfml_change_key_menu.h"
#include "Reader/keyboard.h"

SFMLChangeKeyMenu::SFMLChangeKeyMenu(sf::RenderWindow& window, InReader* reader) : window(window), reader(reader) {}

void SFMLChangeKeyMenu::reset(Commands com) {
    if (this->reader == nullptr)
        return;

    while (this->window.isOpen()) {
        sf::Event event;

        while (this->window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                this->window.close();
            if (event.type == sf::Event::KeyPressed) {
                sf::Keyboard::Key tmp = event.key.code;
                if (Keyboard().key_valid(tmp)) {
                    SFMLConfigScheme config_scheme(true);
                    config_scheme.replace_key(tmp, com);
                    config_scheme.save();
                    reader->update();
                    return;
                }
            }
        }

        this->window.clear();

        SFMLWindow(this->window).draw_texts({"Set the key, click key"},
                                      "/home/mikhail/OOP_lab/project/font/Nunito/Nunito-VariableFont_wght.ttf", 25, -1);

        this->window.display();
    }
}
