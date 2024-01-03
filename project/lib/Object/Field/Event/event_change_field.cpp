#ifndef event_change_field_cpp
#define event_change_field_cpp

#include "event_change_field.h"

EventChangeField::EventChangeField(const EventChangeField& other) : size(other.size), field(other.field) {
    this->change_possability = new Tuple<unsigned>[this->size];
    std::copy(other.change_possability, other.change_possability + other.size, this->change_possability);
}

EventChangeField::EventChangeField(Field& field, std::initializer_list<Tuple<unsigned>> arg) : field(field) {
    this->size = arg.size();
    this->change_possability = new Tuple<unsigned>[this->size];
    size_t i = 0;
    for (auto item : arg) {
        this->change_possability[i] = item;
        ++i;
    }
}

EventChangeField::EventChangeField(Field& field, const Tuple<unsigned>* arg, size_t size) : field(field), size(size) {
    this->change_possability = new Tuple<unsigned>[this->size];
    std::copy(arg, arg + this->size, this->change_possability);
}

EventChangeField::~EventChangeField() { delete [] this->change_possability; }

void EventChangeField::event() {
    for (size_t i = 0; i < this->size; ++i) {
        Cell& c = this->field.get_cell(this->change_possability[i]);
        c.set_passability(!c.is_passability());
    }
}

std::string EventChangeField::get_str() {
    size_t hash = typeid(EventChangeField).hash_code();
    std::string str(reinterpret_cast<const char*>(&hash), sizeof(hash));
    
    str += std::string(reinterpret_cast<const char*>(&this->size), sizeof(this->size));

    for (size_t i = 0; i < this->size; ++i)
        for (size_t j = 0; j < 2; ++j)
            str += std::string(reinterpret_cast<const char*>(&this->change_possability[i][j]), sizeof(this->change_possability[i][j]));
    
    return str;
}

IEvent* EventChangeField::copy() { return new EventChangeField(*this); }

#endif