#ifndef change_cpp
#define change_cpp

#include "event_change_field.h"

EventChangeField::EventChangeField() {
    this->size = 0;
    this->change_possability = nullptr;
}

EventChangeField::EventChangeField(const EventChangeField& other) : size(other.size) {
    if (other.change_possability) {
        this->change_possability = new Tuple<unsigned, 2>[this->size];
        std::copy(other.change_possability, other.change_possability + other.size, this->change_possability);
    }
    else
        this->change_possability = nullptr;
}

EventChangeField::~EventChangeField() {
    delete [] this->change_possability;
}

void EventChangeField::set_event(Tuple<unsigned, 2>* change_possability, size_t size) {
    delete [] this->change_possability;
    this->size = size;
    this->change_possability = new Tuple<unsigned, 2>[this->size];
        std::copy(change_possability, change_possability + size, this->change_possability);
}

void EventChangeField::event(Field& field) {}

EventChangeField* EventChangeField::copy() {
    return new EventChangeField(*this);
}

#endif