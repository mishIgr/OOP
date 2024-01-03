#ifndef event_xp_cpp
#define event_xp_cpp

#include <typeinfo>
#include "event_change_xp.h"

EventChangeXP::EventChangeXP(const EventChangeXP& other) : player(other.player), xp_change(other.xp_change) {}

EventChangeXP::EventChangeXP(Player& player, unsigned xp_change) : player(player), xp_change(xp_change) {}

void EventChangeXP::event() { player.set_life(player.get_life() + this->xp_change); }

std::string EventChangeXP::get_str() {
    size_t hash = typeid(EventChangeXP).hash_code();
    std::string str = std::string(reinterpret_cast<const char*>(&hash), sizeof(hash)) + std::string(reinterpret_cast<const char*>(&this->xp_change), sizeof(this->xp_change));
    return str;
}

IEvent* EventChangeXP::copy() { return new EventChangeXP(*this); }

#endif