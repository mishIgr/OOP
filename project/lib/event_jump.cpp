#ifndef event_jump_cpp
#define event_jump_cpp

#include "event_jump.h"

EventJump::EventJump() : jump_value(0) {}

EventJump::EventJump(const EventJump& other) : jump_value(other.jump_value) {}

void EventJump::set_event(unsigned jump_value) { this->jump_value= jump_value; }

void EventJump::event(Player& player) { player.set_double_jump(player.get_double_jump() + this->jump_value); }

EventJump* EventJump::copy() {
    return new EventJump(*this);
}

#endif