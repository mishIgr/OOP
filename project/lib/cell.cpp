#ifndef cell_cpp
#define cell_cpp

#include "cell.h"
#include <algorithm>

Cell::Cell() : flag_passability(true) {}

Cell::Cell(bool flag_possability) : flag_passability(flag_possability) {}

Cell::Cell(const Cell& other) : Cell(other.flag_passability) {}

Cell::Cell(Cell&& other) {
    std::swap(this->flag_passability, other.flag_passability);
}

Cell& Cell::operator=(const Cell& other) {
    if (this == &other)
        return *this;
    Cell tmp(other);
    std::swap(this->flag_passability, tmp.flag_passability);
    return *this;
}

Cell& Cell::operator=(Cell&& other) {
    if (this == &other)
        return *this;
    std::swap(this->flag_passability, other.flag_passability);
    return *this;
}

void Cell::set_passability(bool flag_possability) { this->flag_passability = flag_possability; }
bool Cell::is_passability() { return this->flag_passability; }

#endif