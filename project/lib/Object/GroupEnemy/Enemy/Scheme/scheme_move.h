//
// Created by mikhail on 22.12.23.
//

#ifndef PROJECT_SCHEME_MOVE_H
#define PROJECT_SCHEME_MOVE_H

#include "Object/Field/field.h"
#include "Object/Player/manage.h"
#include <vector>

class SchemeMove {

    Field& field;
    Manage& manage;
    Tuple<unsigned> coord;
    int point;
    Tuple<unsigned> get_offset_coord(Tuple<unsigned>);

public:

    SchemeMove(Field&, Manage&);
    SchemeMove(Field&, Manage&, Tuple<unsigned>);
    bool move();
    Tuple<unsigned> get_position();
    size_t get_id();

};

#endif //PROJECT_SCHEME_MOVE_H
