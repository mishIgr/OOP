#ifndef keyboard_h
#define keyboard_h

#include "SFML/Graphics.hpp"
#include <map>

class Keyboard {

    std::map<sf::Keyboard::Key, std::string> to_string;

public:

    Keyboard();
    bool key_valid(const sf::Keyboard::Key&);
    std::string get_str(const sf::Keyboard::Key&);

};

#endif