//
// Created by mikhail on 07.12.23.
//

#include "draw_game.h"
#include "Object/Field/Event/event_change_field.h"
#include "Object/Field/Event/event_change_xp.h"
#include "Object/Field/Event/event_jump.h"

DrawGame::DrawGame(IObservable* observable, IWindow* window, GameObject& game_object)
: window(window), game_object(game_object) {
    observable->add(this);
}

void DrawGame::update(State state) {
    if (state.action != NewLevel && state.action != EnemyMove)
        return;
    
    this->window->clear();

    std::string loc_sprite_player("/home/mikhail/OOP_lab/project/sprite/player.png");
    std::string loc_sprite_floor("/home/mikhail/OOP_lab/project/sprite/floor.png");
    std::string loc_sprite_wall("/home/mikhail/OOP_lab/project/sprite/wall.png");
    std::string loc_sprite_end("/home/mikhail/OOP_lab/project/sprite/end.png");
    std::string loc_new_xp("/home/mikhail/OOP_lab/project/sprite/new_xp.png");
    std::string loc_new_jump("/home/mikhail/OOP_lab/project/sprite/new_jump.png");
    std::string loc_night("/home/mikhail/OOP_lab/project/sprite/night.png");

    unsigned begin_x = (this->window->get_size().x - game_object.field.get_width() * 32) / 2;
    unsigned begin_y = (this->window->get_size().y - game_object.field.get_height() * 32) / 2;

    Tuple<unsigned> coord_cell_player = game_object.manage.get_coord_cell();

    this->window->draw_sprite(loc_sprite_floor, { begin_x + (coord_cell_player[0] - 3) * 32, begin_y + (coord_cell_player[1] - 3) * 32 });

    for (unsigned y = coord_cell_player[1] - 2; y < coord_cell_player[1] + 3; ++y) {
        for (unsigned x = coord_cell_player[0] - 2; x < coord_cell_player[0] + 3; ++x) {
            if (!game_object.field.get_cell(y, x).is_passability())
                this->window->draw_sprite(loc_sprite_wall, {begin_x + x * 32, begin_y + y * 32});
            else if (&game_object.field.get_cell(y, x) == &game_object.field.get_exit())
                this->window->draw_sprite(loc_sprite_end, {begin_x + x * 32, begin_y + y * 32});
            else if (dynamic_cast<EventChangeField*>(game_object.field.get_cell(y, x).get_event()))
                this->window->draw_sprite(loc_new_xp, {begin_x + x * 32, begin_y + y * 32});
            else if (dynamic_cast<EventChangeXP*>(game_object.field.get_cell(y, x).get_event()))
                this->window->draw_sprite(loc_new_xp, {begin_x + x * 32, begin_y + y * 32});
            else if (dynamic_cast<EventJump*>(game_object.field.get_cell(y, x).get_event()))
                this->window->draw_sprite(loc_new_xp, {begin_x + x * 32, begin_y + y * 32});
        }
    }

    this->window->draw_sprite(loc_sprite_player, { begin_x + game_object.manage.get_coord()[0], begin_y + game_object.manage.get_coord()[1] });
    this->window->draw_sprite(loc_night, { begin_x + game_object.manage.get_coord()[0] - 112, begin_y + game_object.manage.get_coord()[1] - 112 });

    for (const auto enemy : game_object.group_enemy)
        this->window->draw_sprite(enemy->get_loc_sprite(), { begin_x + enemy->get_coord()[0], begin_y + enemy->get_coord()[1] });

    std::string loc_sprite_xp("/home/mikhail/OOP_lab/project/sprite/xp.png");
    std::string loc_sprite_jump("/home/mikhail/OOP_lab/project/sprite/jump.png");

    begin_x = this->window->get_size().x - 32;
    begin_y = 16;
    for (unsigned i = begin_x; i > begin_x - game_object.player.get_life() * 16; i -= 16)
        this->window->draw_sprite(loc_sprite_xp, { i, begin_y });
    begin_y += 32;
    for (unsigned i = begin_x; i > begin_x - game_object.player.get_double_jump() * 16; i -= 16)
        this->window->draw_sprite(loc_sprite_jump, { i, begin_y });


    this->window->display();
}