#ifndef event_jump_cpp
#define event_jump_cpp

#include "event_jump.h"

EventJump::EventJump(const EventJump& other) : player(other.player), jump_value(other.jump_value) {}

EventJump::EventJump(Player& player, unsigned jump_value) : player(player), jump_value(jump_value) {}

void EventJump::event() { player.set_double_jump(player.get_double_jump() + this->jump_value); }

IEvent* EventJump::copy() { return new EventJump(*this); }

#endif