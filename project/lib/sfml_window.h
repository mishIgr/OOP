//
// Created by mikhail on 19.11.23.
//

#ifndef PROJECT_SFML_WINDOW_H
#define PROJECT_SFML_WINDOW_H

#include "window.h"
#include "SFML/Graphics.hpp"

class SFMLWindow : public IWindow<sf::RenderWindow> {

    sf::RenderWindow& window;

public:

    SFMLWindow(sf::RenderWindow&);

    sf::RenderWindow& get_window();

};

#endif //PROJECT_SFML_WINDOW_H
