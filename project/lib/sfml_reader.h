//
// Created by mikhail on 19.11.23.
//

#ifndef PROJECT_SFML_READER_H
#define PROJECT_SFML_READER_H

#include "reader.h"
#include "SFML/Graphics.hpp"
#include "sfml_config_scheme.h"
#include "window.h"
#include <map>

template<typename Window>
class SFMLReader : public InReader {

    IWindow<Window>* window;

public:

    SFMLReader(IWindow<Window>*);

    std::vector<Commands> get_commands();
    std::vector<std::string> get_key_str();
    void reset_config();

};

template<typename Window>
SFMLReader<Window>::SFMLReader(IWindow<Window>* window) : window(window) {}

template<typename Window>
std::vector<Commands> SFMLReader<Window>::get_commands() {
    std::vector<Commands> commands;

    std::map<sf::Keyboard::Key, Commands> to_command(std::move(SFMLConfigScheme(true).get_map_to_command()));
    sf::Event event;
    while (this->window->get_window().pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            commands.push_back(Commands::Close);
            return std::move(commands);
        }
        if (event.type == sf::Event::KeyPressed) {
            auto it = to_command.find(event.key.code);
            if (it != to_command.end())
                commands.push_back(to_command[event.key.code]);
        }
    }
    return std::move(commands);
}

template<typename Window>
std::vector<std::string> SFMLReader<Window>::get_key_str() {
    std::vector<std::string> key_config;
    for (size_t i = 0; i < 12; ++i)
        for (const auto& item : SFMLConfigScheme(true).get_map_to_command())
            if (item.second == i)
                key_config.push_back(Keyboard().get_str(item.first));
    return std::move(key_config);
}

template<typename Window>
void SFMLReader<Window>::reset_config() { SFMLConfigScheme(false).save(); }

#endif //PROJECT_SFML_READER_H
