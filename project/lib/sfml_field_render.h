//
// Created by mikhail on 20.11.23.
//

#ifndef PROJECT_SFML_FIELD_RENDER_H
#define PROJECT_SFML_FIELD_RENDER_H

#include "field_render.h"
#include "Field/field.h"
#include "Player/manage.h"
#include "window.h"
#include "SFML/Graphics.hpp"
#include <iostream>

template<typename Window>
class SFMLRenderField : public IRenderFiled {

    IWindow<Window>* window;
    Field& field;
    Manage& manage;

public:

    SFMLRenderField(IWindow<Window>*, Field&, Manage&);

    void draw();

};

template<typename Window>
SFMLRenderField<Window>::SFMLRenderField(IWindow<Window>* window, Field& field, Manage& manage)
: window(window), field(field), manage(manage) {}

template<typename Window>
void SFMLRenderField<Window>::draw() {
    sf::Texture texture_wall;
    texture_wall.loadFromFile("/home/mikhail/OOP_lab/project/sprite/wall.png");
    sf::Texture texture_paul;
    texture_paul.loadFromFile("/home/mikhail/OOP_lab/project/sprite/paul.png");
    sf::Texture texture_player;
    texture_player.loadFromFile("/home/mikhail/OOP_lab/project/sprite/player.png");

    unsigned begin_x = (this->window->get_window().getSize().x - field.get_width() * 32) / 2;
    unsigned begin_y = (this->window->get_window().getSize().y - field.get_height() * 32) / 2;

    for (unsigned y = 0; y < field.get_height(); ++y) {
        for (unsigned x = 0; x < field.get_width(); ++x) {
            sf::Sprite sprite;
            sprite.setPosition(begin_x + x * 32, begin_y + y * 32);
            if (field.get_cell(y, x).is_passability())
                sprite.setTexture(texture_paul);
            else
                sprite.setTexture(texture_wall);
            this->window->get_window().draw(sprite);
        }
    }

    sf::Sprite sprite;
    sprite.setPosition(begin_x + manage.get_coord()[0] * 32, begin_y + manage.get_coord()[1] * 32);
    sprite.setTexture(texture_player);
    this->window->get_window().draw(sprite);
}

#endif //PROJECT_SFML_FIELD_RENDER_H
