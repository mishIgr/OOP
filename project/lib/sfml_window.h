//
// Created by mikhail on 19.11.23.
//

#ifndef PROJECT_SFML_WINDOW_H
#define PROJECT_SFML_WINDOW_H

#include "window.h"
#include "SFML/Graphics.hpp"

class SFMLWindow : public IWindow {

    sf::RenderWindow& window;

public:

    SFMLWindow(sf::RenderWindow&);
    bool is_open();
    void close();
    void clear();
    void display();
    Vector2U get_size();
    std::vector<Key> poll_event();
    void draw_texts(std::vector<std::string>, std::string, unsigned, unsigned);
    void draw_texts(std::vector<std::string>, std::string, unsigned, unsigned, std::pair<std::pair<float, float>, std::pair<float, float>>);
    void draw_sprite(std::string, std::pair<float, float>);

};

#endif //PROJECT_SFML_WINDOW_H
