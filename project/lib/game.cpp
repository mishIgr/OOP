//
// Created by mikhail on 27.11.23.
//
#include <iostream>
#include "game.h"
#include "generate_level.h"
#include <map>

Game::Game(IWindow* window, InReader* reader, IMenu* game_pause, GameObject& game_object)
: window(window), reader(reader), game_pause(game_pause), game_object(game_object) {}

void Game::add(IObserver* observer) { this->observers.push_back(observer); }

void Game::del(IObserver* observer) {
    this->observers.erase(
            std::remove(this->observers.begin(), this->observers.end(), observer),
            this->observers.end()
            );
}

void Game::notify(State state) {
    for (auto observer : this->observers)
        observer->update(state);
}

void Game::render() {
    if (this->reader == nullptr || this->window == nullptr)
        return;

    GenerateLevel generate_level(game_object);
    if (!generate_level.generate(1))
        return;

    this->notify({NewLevel, {None, ""}});

    std::map<Commands, Direct> to_direct {
            {Up, UP},
            {Down, DOWN},
            {Left, LEFT},
            {Right, RIGHT},
            {DUp, D_UP},
            {DDown, D_DOWN},
            {DLeft, D_LEFT},
            {DRight, D_RIGHT}
    };

    while (this->window->is_open()) {
        for (auto key: this->reader->get_commands(true)) {
            if (key.com == Close)
                this->window->close();
            else if (key.com == Restart) {
                this->notify({Lose, key});
                generate_level.restart();
            }
            else if (key.com == Back)
                this->game_pause->render();
            else {
                auto p = to_direct.find(key.com);
                if (p != to_direct.end()) {
                    this->game_object.manage.move(to_direct[key.com]);
                    if (&this->game_object.field.get_cell(this->game_object.manage.get_coord_cell()) == &this->game_object.field.get_exit()) {
                        if (!generate_level.next_level())
                            return;
                        this->notify({NewLevel, key});
                    }
                }
            }
            this->notify({KeyboardPush, key});
        }
        game_object.group_enemy.move();
        for (const auto enemy : game_object.group_enemy) {
            Tuple<unsigned> enemy_coord = { (enemy->get_coord()[0] + 15) / 32, (enemy->get_coord()[1] + 15) / 32 };
            if (enemy_coord[0] == game_object.manage.get_coord_cell()[0] && enemy_coord[1] == game_object.manage.get_coord_cell()[1])
                if (!game_object.player.get_invulnerability())
                    enemy->interaction();
            if (game_object.player.get_invulnerability())
                game_object.player.set_invulnerability(game_object.player.get_invulnerability() - 1);
        }
        this->notify({EnemyMove, {}});
    }
}
