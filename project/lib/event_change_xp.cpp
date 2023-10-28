#ifndef event_xp_cpp
#define event_xp_cpp

#include "event_change_xp.h"

EventChangeXP::EventChangeXP(const EventChangeXP& other) : player(other.player), xp_change(other.xp_change) {}

EventChangeXP::EventChangeXP(Player& player, unsigned xp_change) : player(player), xp_change(xp_change) {}

void EventChangeXP::event() { player.set_life(player.get_life() + this->xp_change); }

IEvent* EventChangeXP::copy() { return new EventChangeXP(*this); }

#endif