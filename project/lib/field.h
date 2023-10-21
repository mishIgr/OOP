#ifndef field_h
#define field_h

#include "cell.h"
#include "tuple.h"

class Field {

    unsigned width;
    unsigned height;
    Cell** field;

    Cell* entrance;
    Cell* exit;

    Field(unsigned, unsigned, Cell**);

    void swap(Field&);

public:

    Field();
    Field(unsigned, unsigned);
    Field(const Field&);
    Field(Field&&);
    ~Field();

    Field& operator=(const Field&);
    Field& operator=(Field&&);

    unsigned get_width();
    unsigned get_height();

    Cell& get_cell(unsigned, unsigned);
    Cell& get_cell(Tuple<unsigned, 2>);

    Tuple<unsigned, 2> get_tuple(unsigned, unsigned);
};

#endif