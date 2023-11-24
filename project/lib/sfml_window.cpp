//
// Created by mikhail on 19.11.23.
//

#include "sfml_window.h"

SFMLWindow::SFMLWindow(sf::RenderWindow& window) : window(window) {}

sf::RenderWindow& SFMLWindow::get_window() { return this->window; }
