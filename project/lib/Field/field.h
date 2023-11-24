#ifndef field_h
#define field_h

#include <initializer_list>
#include "Field/cell.h"
#include "tuple.h"

class Field {

    unsigned width;
    unsigned height;
    Cell** field;

    Cell* entrance;
    Cell* exit;

    void swap(Field&);

public:

    Field();
    Field(unsigned, unsigned);
    Field(const Field&);
    Field(Field&&);
    ~Field();

    Field& operator=(const Field&);
    Field& operator=(Field&&);

    unsigned get_width() const;
    unsigned get_height() const;

    Cell& get_cell(unsigned, unsigned);
    Cell& get_cell(Tuple<unsigned>);

    bool in_field(unsigned, unsigned) const;
    bool in_field(Tuple<unsigned>) const;
    
};

#endif