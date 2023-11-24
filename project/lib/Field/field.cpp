#ifndef field_cpp
#define field_cpp

#include "field.h"
#include <algorithm>

Field::Field() : Field(6, 6) {}

Field::Field(unsigned width, unsigned height) {
    this->height = height > 6 ? height : 6;
    this->width = width > 6 ? width : 6;

    this->field = new Cell*[this->height];
    for (int y = 0; y < this->height; ++y)
        this->field[y] = new Cell[this->width];
        
    this->entrance = this->field[2] + 2;
    this->exit = this->field[this->height - 3] + this->width - 3;
}

void Field::swap(Field& other) {
    std::swap(this->field, other.field);
    std::swap(this->entrance, other.entrance);
    std::swap(this->exit, other.exit);
    std::swap(this->width, other.width);
    std::swap(this->height, other.height);
}

Field::Field(const Field& other) : Field(other.width, other.height) {
    for (int y = 0; y < this->height; ++y)
        for (int x = 0; x < this->width; ++x)
            this->field[y][x] = other.field[y][x];
}

Field::Field(Field&& other) : width(0), height(0), field(nullptr), entrance(nullptr), exit(nullptr) {
    this->swap(other);
}

Field::~Field() {
    for (int y = 0; y < this->height; ++y)
        delete[] this->field[y];
    delete[] this->field;
}

Field& Field::operator=(const Field& other) {
    if (this == &other)
        return *this;

    Field tmp(other);
    this->swap(tmp);
    return *this;
}

Field& Field::operator=(Field&& other) {
    if (this == &other)
        return *this;
        
    this->swap(other);
    return *this;
}

unsigned Field::get_width() const { return this->width; }
unsigned Field::get_height() const { return this->height; }

Cell& Field::get_cell(unsigned y, unsigned x) {
    return this->field[y][x];
}

Cell& Field::get_cell(Tuple<unsigned> coord) {
    return this->field[coord[1]][coord[0]];
}

bool Field::in_field(unsigned x, unsigned y) const {
    return x < this->width && y < this->height;
}

bool Field::in_field(Tuple<unsigned> coord) const {
    return coord[0] < this->width && coord[1] < this->height;
}

#endif