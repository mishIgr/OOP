//
// Created by mikhail on 20.11.23.
//

#ifndef PROJECT_SFML_CHANGE_KEY_MENU_H
#define PROJECT_SFML_CHANGE_KEY_MENU_H

#include "Menu/change_key_menu.h"
#include "sfml_window.h"
#include "Reader/sfml_config_scheme.h"
#include "SFML/Graphics.hpp"

class SFMLChangeKeyMenu : public IChangeMenu {

    sf::RenderWindow& window;
    InReader* reader;

public:

    SFMLChangeKeyMenu(sf::RenderWindow&, InReader*);

    void reset(Commands);

};

#endif //PROJECT_SFML_CHANGE_KEY_MENU_H
