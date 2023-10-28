#ifndef manage_cpp
#define manage_cpp

#include "manage.h"
#include <limits>
#include <map>

Manage::Manage(Player& player, Field& field) : player(player), field(field), coord{{ 2, 2 }} {}

Manage::Manage(Player& player, Field& field, unsigned x, unsigned y) : player(player), field(field), coord({ 2, 2 }) {
    if (field.get_cell(x, y).is_passability()) {
        this->coord[0] = x < field.get_width() ? x : field.get_width() - 1;
        this->coord[1]= y < field.get_height() ? y : field.get_height() - 1;
    }
}

Manage::Manage(Player& player, Field& field, Tuple<unsigned> coord) : player(player), field(field), coord({ 2, 2 }) {
    if (field.get_cell(coord).is_passability()) {
        this->coord[0] = coord[0] < field.get_width() ? coord[0] : field.get_width() - 1;
        this->coord[1]= coord[1] < field.get_height() ? coord[1] : field.get_height() - 1;
    }
}

bool Manage::move(Direct direct) {

    if (direct >= D_UP && !this->player.get_double_jump())
        return false;

    if (!this->player.is_alive())
        return false;

    std::map<Direct, Tuple<unsigned>> offset {
        {UP, { std::numeric_limits<unsigned>::max(), 0 }},
        {LEFT, { 0, std::numeric_limits<unsigned>::max() }},
        {DOWN, { 1, 0 }},
        {RIGHT, { 0, 1 }},
        {D_UP, { std::numeric_limits<unsigned>::max() - 1, 0 }},
        {D_LEFT, { 0, std::numeric_limits<unsigned>::max() - 1 }},
        {D_DOWN, { 2, 0 }},
        {D_RIGHT, { 0, 2 }}
    };

    if (!field.get_cell(this->coord + offset[direct]).is_passability())
        return false;
    
    this->coord += offset[direct];
    return true;
}

void Manage::damage(unsigned damage) { this->player.set_life(damage > this->player.get_life() ? 0 : this->player.get_life() - damage); }

void Manage::heal(unsigned heal) { this->player.set_life(heal + this->player.get_life()); }

#endif