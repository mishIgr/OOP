#ifndef manage_cpp
#define manage_cpp

#include "manage.h"

Manage::Manage(Player& player, Field& field) : player(player), field(field), x(0), y(0) {}

Manage::Manage(Player& player, Field& field, unsigned x, unsigned y) : player(player), field(field) {
    this->x = x < field.get_width() ? x : field.get_width() - 1;
    this->y= y < field.get_height() ? y : field.get_height() - 1;
}

bool Manage::move(Direct direct) {

    if (direct >= D_UP && !this->player.get_double_jump())
        return false;

    if (!this->player.is_alive())
        return false;

    switch (direct) {
    case UP:
        if (this->y > 0 && this->field.get_cell(this->y - 1, this->x).is_passability()) {
            this->y--;
            return true;
        }
        else
            return false;
    case LEFT:
        if (this->x > 0 && this->field.get_cell(this->y, this->x - 1).is_passability()) {
            this->x--;
            return true;
        }
        else
            return false;
    case DOWN:
        if (this->y < this->field.get_height() && this->field.get_cell(this->y + 1, this->x).is_passability()) {
            this->y++;
            return true;
        }
        else
            return false;
    case RIGHT:
        if (this->x < this->field.get_width() && this->field.get_cell(this->y, this->x + 1).is_passability()) {
            this->x++;
            return true;
        }
        else
            return false;
    case D_UP:
        if (this->y > 1 && this->field.get_cell(this->y - 2, this->x).is_passability()) {
            this->y -= 2;
            this->player.set_double_jump(this->player.get_double_jump() - 1);
            return true;
        }
        else
            return false;
    case D_LEFT:
        if (this->x > 1 && this->field.get_cell(this->y, this->x - 2).is_passability()) {
            this->x -= 2;
            this->player.set_double_jump(this->player.get_double_jump() - 1);
            return true;
        }
        else
            return false;
    case D_DOWN:
        if (this->y < (this->field.get_height() - 1) && this->field.get_cell(this->y + 2, this->x).is_passability()) {
            this->y += 2;
            this->player.set_double_jump(this->player.get_double_jump() - 1);
            return true;
        }
        else
            return false;
    case D_RIGHT:
        if (this->x < (this->field.get_width() - 1) && this->field.get_cell(this->y, this->x + 2).is_passability()) {
            this->x += 2;
            this->player.set_double_jump(this->player.get_double_jump() - 1);
            return true;
        }
        else
            return false;
    }
    return false;
}

void Manage::damage(unsigned damage) { this->player.set_life(damage > this->player.get_life() ? 0 : this->player.get_life() - damage); }

void Manage::heal(unsigned heal) { this->player.set_life(heal + this->player.get_life()); }

#endif