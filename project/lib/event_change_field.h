#ifndef change_h
#define change_h

#include "event.h"
#include "field.h"

class EventChangeField : public IEvent {
public:
    void event(Field& field) {
        field.get_cell(0, 0).set_passability(!field.get_cell(0, 0).is_passability());
    }
};

#endif