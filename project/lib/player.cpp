#ifndef player_cpp
#define player_cpp

#include "player.h"

Player::Player() : counter_life(5), counter_double_jump(5) {}

Player::Player(unsigned counter_life, unsigned counter_double_jump) {
    this->counter_life = counter_life > 20 ? 20 : counter_life;
    this->counter_double_jump = counter_double_jump > 8 ? 8 : counter_double_jump;
}

unsigned Player::get_life() const { return this->counter_life; }
void Player::set_life(unsigned counter_life) { this->counter_life = counter_life > 20 ? 20 : counter_life; }
bool Player::is_alive() const { return this->counter_life != 0; }

unsigned Player::get_double_jump() const { return this->counter_double_jump; }
void Player::set_double_jump(unsigned counter_double_jump) { this->counter_double_jump = counter_double_jump > 8 ? 8 : counter_double_jump; }

#endif