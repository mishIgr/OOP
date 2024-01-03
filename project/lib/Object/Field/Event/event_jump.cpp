#ifndef event_jump_cpp
#define event_jump_cpp

#include <typeinfo>
#include "event_jump.h"

EventJump::EventJump(const EventJump& other) : player(other.player), jump_value(other.jump_value) {}

EventJump::EventJump(Player& player, unsigned jump_value) : player(player), jump_value(jump_value) {}

void EventJump::event() { player.set_double_jump(player.get_double_jump() + this->jump_value); }

std::string EventJump::get_str() {
    size_t hash = typeid(EventJump).hash_code();
    std::string str = std::string(reinterpret_cast<const char*>(&hash), sizeof(hash)) + std::string(reinterpret_cast<const char*>(&this->jump_value), sizeof(this->jump_value));
    return str;
}

IEvent* EventJump::copy() { return new EventJump(*this); }

#endif