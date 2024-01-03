//
// Created by mikhail on 19.12.23.
//

#ifndef PROJECT_SPRITES_H
#define PROJECT_SPRITES_H

#include "SFML/Graphics.hpp"

class Sprites {
//    sf::Texture texture;
//    texture.loadFromFile("/home/mikhail/OOP_lab/project/sprite/player.png");
//    this->sprites["player"] = sf::Sprite(texture);
//    texture.loadFromFile("/home/mikhail/OOP_lab/project/sprite/floor.png");
//    this->sprites["floor"] = sf::Sprite(texture);
//    texture.loadFromFile("/home/mikhail/OOP_lab/project/sprite/wall.png");
//    this->sprites["wall"] = sf::Sprite(texture);
//    texture.loadFromFile("/home/mikhail/OOP_lab/project/sprite/end.png");
//    this->sprites["end"] = sf::Sprite(texture);
//    texture.loadFromFile("/home/mikhail/OOP_lab/project/sprite/new_xp.png");
//    this->sprites["new_xp"] = sf::Sprite(texture);
//    texture.loadFromFile("/home/mikhail/OOP_lab/project/sprite/new_jump.png");
//    this->sprites["new_jump"] = sf::Sprite(texture);
//    texture.loadFromFile("/home/mikhail/OOP_lab/project/sprite/xp.png");
//    this->sprites["xp"] = sf::Sprite(texture);
//    texture.loadFromFile("/home/mikhail/OOP_lab/project/sprite/jump.png");
//    this->sprites["jump"] = sf::Sprite(texture);
public:

    enum Name {
        player,
        floor,
        wall,

    };

    virtual void draw() = 0;

};

#endif //PROJECT_SPRITES_H
