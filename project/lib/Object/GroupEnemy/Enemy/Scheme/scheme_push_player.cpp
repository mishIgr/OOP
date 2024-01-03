//
// Created by mikhail on 25.12.23.
//

#include "scheme_push_player.h"
#include <map>

SchemePushPlayer::SchemePushPlayer(Player& player, Manage& manage) : player(player), manage(manage) {}

bool SchemePushPlayer::interaction() {
    Tuple<unsigned> coord = manage.get_coord();
    unsigned x = (coord[0] % 32) / 16;
    unsigned y = (coord[0] % 32) / 16;

    std::map<std::pair<unsigned, unsigned>, Direct> to_d_direct {
            {{0, 0}, D_UP},
            {{1, 0}, D_LEFT},
            {{0, 1}, D_RIGHT},
            {{1, 1}, D_DOWN}
    };
    std::map<std::pair<unsigned, unsigned>, Direct> to_direct {
            {{0, 0}, UP},
            {{1, 0}, LEFT},
            {{0, 1}, RIGHT},
            {{1, 1}, DOWN}
    };

    player.set_double_jump(player.get_double_jump() + 1);
    if (!manage.move(to_d_direct[{x, y}])) {
        for (int i = 0; i < 5 && manage.move(to_direct[{x, y}]); i++);
        player.set_double_jump(player.get_double_jump() - 1);
    }
}

size_t SchemePushPlayer::get_id() { return typeid(*this).hash_code(); }