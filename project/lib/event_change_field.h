#ifndef change_h
#define change_h

#include "event.h"
#include "field.h"
#include "tuple.h"

class EventChangeField : public IEvent {

    Tuple<unsigned, 2>* change_possability;
    size_t size;
    EventChangeField(const EventChangeField&);

public:

    EventChangeField();
    ~EventChangeField();

    void set_event(Tuple<unsigned, 2>*, size_t);
    void event(Field& field);

    EventChangeField* copy();
};

#endif