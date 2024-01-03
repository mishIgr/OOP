//
// Created by mikhail on 21.12.23.
//

#ifndef PROJECT_SCHEME_MOVE_WALL_H
#define PROJECT_SCHEME_MOVE_WALL_H

#include "tuple.h"
#include "Object/Field/field.h"

class SchemeMoveWall {

    Tuple<unsigned> coord;
    Tuple<unsigned> offset = { 1, 2 };
    Field& field;

public:

    SchemeMoveWall(Field&);
    SchemeMoveWall(Field&, Tuple<unsigned>);
    bool move();
    Tuple<unsigned> get_position();
    size_t get_id();

};

#endif //PROJECT_SCHEME_MOVE_WALL_H
