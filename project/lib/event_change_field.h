#ifndef event_change_field_h
#define event_change_field_h

#include "event.h"
#include "field.h"
#include "tuple.h"
#include <initializer_list>
#include <iostream>

class EventChangeField : public IEvent {

    Field& field;
    Tuple<unsigned>* change_possability;
    size_t size;
    EventChangeField(const EventChangeField&);

public:

    EventChangeField(Field&, std::initializer_list<Tuple<unsigned>>);
    ~EventChangeField();
    
    void event();

    IEvent* copy();

};

#endif