#ifndef event_xp_h
#define event_xp_h

#include "Field/Event/event.h"
#include "Player/player.h"

class EventChangeXP : public IEvent {

    Player& player;
    unsigned xp_change;
    EventChangeXP(const EventChangeXP&);

public:

    EventChangeXP(Player&, unsigned);

    void event();
    std::string get_str();

    IEvent* copy();

};

#endif