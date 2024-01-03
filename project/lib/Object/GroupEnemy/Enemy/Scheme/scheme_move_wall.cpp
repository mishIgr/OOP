//
// Created by mikhail on 21.12.23.
//

#include "scheme_move_wall.h"

SchemeMoveWall::SchemeMoveWall(Field& field) : field(field), coord({ 0, 0 }) {}

SchemeMoveWall::SchemeMoveWall(Field& field, Tuple<unsigned> coord) : field(field), coord(std::move(coord)) {}

bool SchemeMoveWall::move() {
    if ((this->coord[0] + this->offset[0]) / 32 >= this->field.get_width() - 1)
        this->offset[0] = -this->offset[0];
    else if (int(this->coord[0] + this->offset[0]) < 0)
        this->offset[0] = -this->offset[0];
    if ((this->coord[1] + this->offset[1]) / 32 >= this->field.get_width() - 1)
        this->offset[1] = -this->offset[1];
    else if (int(this->coord[1] + this->offset[1]) < 0)
        this->offset[1] = -this->offset[1];
    this->coord += this->offset;
    return true;
}

Tuple<unsigned> SchemeMoveWall::get_position() { return this->coord; }

size_t SchemeMoveWall::get_id() { return typeid(*this).hash_code(); }