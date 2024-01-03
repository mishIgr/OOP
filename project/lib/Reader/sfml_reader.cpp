//
// Created by mikhail on 27.11.23.
//

#include "Reader/sfml_reader.h"
#include "Reader/keyboard.h"

SFMLReader::SFMLReader(sf::RenderWindow& window) : window(window) {
    for (const auto& pair : SFMLConfigScheme().get_map_to_command()) {
        if (pair.second <= Right && pair.second >= Up)
            this->commands_move[pair.first] = pair.second;
        else
            this->commands_other[pair.first] = pair.second;
    }
}

std::vector<Key> SFMLReader::get_commands(bool track_push) {
    std::vector<Key> commands;

    sf::Event event;

    while (this->window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            commands.push_back({Commands::Close, ""});
            return std::move(commands);
        }
        if (event.type == sf::Event::KeyPressed) {
            auto it_other = this->commands_other.find(event.key.code);
            auto it_move = this->commands_move.find(event.key.code);
            if (it_move != commands_move.end() && !track_push)
                commands.push_back({it_move->second, Keyboard().get_str(event.key.code)});
            else if (it_other != commands_other.end())
                commands.push_back({it_other->second, Keyboard().get_str(event.key.code)});
            else if (Keyboard().key_valid(event.key.code))
                commands.push_back({None, Keyboard().get_str(event.key.code)});
        }
    }

    if (track_push)
        for (const auto& pair : this->commands_move)
            if (sf::Keyboard::isKeyPressed(pair.first))
                commands.push_back({pair.second, Keyboard().get_str(pair.first)});

    return std::move(commands);
}

std::vector<std::string> SFMLReader::get_key_str() {
    std::vector<std::string> key_config;
    for (size_t i = 0; i < 12; ++i)
        for (const auto& item : SFMLConfigScheme(true).get_map_to_command())
            if (item.second == i)
                key_config.push_back(Keyboard().get_str(item.first));
    return std::move(key_config);
}

void SFMLReader::reset_config() {
    SFMLConfigScheme(false).save();
    this->update();
}

void SFMLReader::update() {
    this->commands_move.clear();
    for (const auto& pair : SFMLConfigScheme().get_map_to_command()) {
        if (pair.second <= Right && pair.second >= Up)
            this->commands_move[pair.first] = pair.second;
        else
            this->commands_move[pair.first] = pair.second;
    }
}
