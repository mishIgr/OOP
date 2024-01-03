//
// Created by mikhail on 22.12.23.
//

#include "scheme_attack_player.h"

SchemeAttackPlayer::SchemeAttackPlayer(Manage& manage) : manage(manage) {}

bool SchemeAttackPlayer::interaction() {
    manage.damage(1);
    return true;
}

size_t SchemeAttackPlayer::get_id() { return typeid(*this).hash_code(); }