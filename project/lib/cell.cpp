#ifndef cell_cpp
#define cell_cpp

#include "cell.h"
#include <algorithm>

Cell::Cell() : Cell(true) {}

Cell::Cell(bool flag_possability) : flag_passability(flag_possability), event(nullptr) {}

Cell::Cell(IEvent* event) : flag_passability(true), event(event) {}

Cell::Cell(bool flag_possability, IEvent* event) : flag_passability(flag_possability), event(event) {}

Cell::Cell(const Cell& other) : Cell(other.flag_passability) {
    this->event = event->copy();
}

Cell::Cell(Cell&& other) {
    std::swap(this->flag_passability, other.flag_passability);
    std::swap(this->event, other.event);
}

Cell& Cell::operator=(const Cell& other) {
    if (this == &other)
        return *this;
        
    Cell tmp(other);
    std::swap(this->flag_passability, tmp.flag_passability);
    std::swap(this->event, tmp.event);
    return *this;
}

Cell& Cell::operator=(Cell&& other) {
    if (this == &other)
        return *this;

    std::swap(this->flag_passability, other.flag_passability);
    std::swap(this->event, other.event);
    return *this;
}

void Cell::set_passability(bool flag_possability) { this->flag_passability = flag_possability; }
bool Cell::is_passability() { return this->flag_passability; }

#endif