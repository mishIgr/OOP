#ifndef field_cpp
#define field_cpp

#include "field.h"
#include <algorithm>

Field::Field() : Field(2, 2) {}

Field::Field(unsigned width, unsigned height) {
    this->height = height > 1 ? height : 2;
    this->width = width > 1 ? width : 2;

    this->field = new Cell*[this->height];
    for (int y = 0; y < this->height; ++y)
        this->field[y] = new Cell[this->width];
        
    this->entrance = this->field[0];
    this->exit = this->field[this->height - 1] + this->width - 1;
}

Field::Field(unsigned width, unsigned height, Cell** arr) : Field(width, height) {
    for (int y = 0; y < this->height; ++y)
        for (int x = 0; x < this->width; ++x)
            this->field[y][x] = arr[y][x];
}

void Field::swap(Field& other) {
    std::swap(this->field, other.field);
    std::swap(this->entrance, other.entrance);
    std::swap(this->exit, other.exit);
    std::swap(this->width, other.width);
    std::swap(this->height, other.height);
}

Field::Field(const Field& other) : Field(other.width, other.height, other.field) {}

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

unsigned Field::get_width() { return this->width; }
unsigned Field::get_height() { return this->height; }

Cell& Field::get_cell(unsigned y, unsigned x) {
    y = y % this->height;
    x = x % this->width;
    return this->field[y][x];
}

#endif