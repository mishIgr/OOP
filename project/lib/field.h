#ifndef field_h
#define field_h

#include "cell.h"

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
};

#endif