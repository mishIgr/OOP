#ifndef manage_cpp
#define manage_cpp

#include "manage.h"
#include <limits>
#include <map>

Manage::Manage(Player& player, Field& field) : player(player), field(field), coord({ 2, 2 }) {}

Manage::Manage(Player& player, Field& field, Tuple<unsigned> coord) : Manage(player, field) {
    this->coord = coord;
}

Manage::Manage(Player& player, Field& field, unsigned x, unsigned y) : Manage(player, field, { x, y }) {}

Manage::Manage(const Manage& other) : Manage(other.player, other.field, other.coord) {}

Manage::Manage(Manage&& other) : player(other.player), field(other.field) { std::swap(this->coord, other.coord); }

Manage& Manage::operator=(const Manage& other) {
    if (this == &other)
        return *this;
    
    Manage tmp(other);
    std::swap(this->player, tmp.player);
    std::swap(this->field, tmp.field);
    std::swap(this->coord, tmp.coord);
    return *this;
}

Manage& Manage::operator=(Manage&& other) {
    if (this == &other)
        return *this;
    
    std::swap(this->player, other.player);
    std::swap(this->field, other.field);
    std::swap(this->coord, other.coord);
    return *this;
}

bool Manage::move(Direct direct) {

    if (!this->player.is_alive())
        return false;

    std::map<Direct, Tuple<unsigned>> offset {
        {UP, { 0, std::numeric_limits<unsigned>::max() }},
        {LEFT, { std::numeric_limits<unsigned>::max(), 0 }},
        {DOWN, { 0, 1 }},
        {RIGHT, { 1, 0 }},
        {D_UP, { 0, std::numeric_limits<unsigned>::max() - 63 }},
        {D_LEFT, { std::numeric_limits<unsigned>::max() - 63, 0 }},
        {D_DOWN, { 0, 64 }},
        {D_RIGHT, { 64, 0 }}
    };

    Tuple<unsigned> new_coord = this->coord + offset[direct];

    if (!(field.get_cell({new_coord[0] / 32, new_coord[1] / 32}).is_passability()
        && field.get_cell({(new_coord[0] + 31) / 32, new_coord[1] / 32}).is_passability()
           && field.get_cell({new_coord[0] / 32, (new_coord[1] + 31) / 32}).is_passability()
              && field.get_cell({(new_coord[0] + 31) / 32, (new_coord[1] + 31) / 32}).is_passability()))
        return false;

    if (direct >= D_UP && !this->player.get_double_jump())
        return false;
    else if (direct >= D_UP)
        this->player.set_double_jump(this->player.get_double_jump() - 1);
    
    this->coord = new_coord;

    if (field.get_cell(this->get_coord_cell()).get_event())
        field.get_cell(this->get_coord_cell()).get_event()->event();

    field.get_cell(this->get_coord_cell()).set_event(nullptr);

    return true;
}

void Manage::damage(unsigned damage) {
    player.set_invulnerability(damage * 100);
    this->player.set_life(damage > this->player.get_life() ? 0 : this->player.get_life() - damage);
}

void Manage::heal(unsigned heal) { this->player.set_life(heal + this->player.get_life()); }

Tuple<unsigned> Manage::get_coord() { return this->coord; }

Tuple<unsigned> Manage::get_coord_cell() { return {(this->coord[0] + 15) / 32, (this->coord[1] + 15) / 32}; }

#endif