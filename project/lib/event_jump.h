#ifndef event_jump_h
#define event_jump_h

#include "event.h"
#include "player.h"
#include "tuple.h"

class EventJump : public IEvent {

    unsigned jump_value;
    EventJump(const EventJump&);

public:

    EventJump();

    void set_event(unsigned);
    void event(Player&);

    EventJump* copy();
};

#endif