#ifndef cell_h
#define cell_h

#include "event.h"

class Cell {

    IEvent* event;
    bool flag_passability;

public:

    Cell();
    Cell(bool);
    Cell(IEvent*);
    Cell(bool, IEvent*);
    Cell(const Cell&);
    Cell(Cell&&);

    Cell& operator=(const Cell&);
    Cell& operator=(Cell&&);

    void set_passability(bool);
    bool is_passability();

    void set_event(IEvent*);

};

#endif