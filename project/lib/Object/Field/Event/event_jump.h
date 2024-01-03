#ifndef event_jump_h
#define event_jump_h

#include "event.h"
#include "Object/Player/player.h"

class EventJump : public IEvent {

    Player& player;
    unsigned jump_value;
    EventJump(const EventJump&);

public:

    EventJump(Player&, unsigned);

    void event();
    std::string get_str();

    IEvent* copy();

};

#endif