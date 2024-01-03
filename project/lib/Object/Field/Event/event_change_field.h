#ifndef event_change_field_h
#define event_change_field_h

#include <initializer_list>
#include "event.h"
#include "Object/Field/field.h"
#include "tuple.h"

class EventChangeField : public IEvent {

    Field& field;
    Tuple<unsigned>* change_possability;
    size_t size;
    EventChangeField(const EventChangeField&);

public:

    EventChangeField(Field&, std::initializer_list<Tuple<unsigned>>);
    EventChangeField(Field&, const Tuple<unsigned>*, size_t);
    ~EventChangeField();
    
    void event();
    std::string get_str();

    IEvent* copy();

};

#endif