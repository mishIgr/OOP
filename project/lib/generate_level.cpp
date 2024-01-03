//
// Created by mikhail on 27.11.23.
//

#include "generate_level.h"
#include "Object/Field/Event/generate_event.h"
#include "Object/GroupEnemy/Enemy/Scheme/scheme_move_wall.h"
#include "Object/GroupEnemy/Enemy/Scheme/scheme_attack_player.h"
#include "Object/GroupEnemy/Enemy/Scheme/scheme_move.h"
#include "Object/GroupEnemy/Enemy/Scheme/scheme_push_player.h"

std::string GenerateLevel::file_fun(unsigned num) {
    return "/home/mikhail/OOP_lab/project/bin/level/level" + std::to_string(num) + ".bin";
}

GenerateLevel::GenerateLevel(GameObject& game_object) : game_object(game_object), order_level(1) {}

bool GenerateLevel::generate(unsigned order_next_level) {
    std::string content;
    if (!FileMahager().read_bin(this->file_fun(order_next_level), content))
        return false;

    unsigned width = *reinterpret_cast<const unsigned *>(content.substr(0, sizeof(unsigned)).c_str());
    content = content.substr(sizeof(unsigned));
    unsigned height = *reinterpret_cast<const unsigned *>(content.substr(0, sizeof(unsigned)).c_str());
    content = content.substr(sizeof(unsigned));

    Field f(width, height);
    game_object.field = std::move(f);

    GenerateEvent generate_event(game_object.field, game_object.player);
    for (size_t y = 0; y < game_object.field.get_height(); ++y) {
        for (size_t x = 0; x < game_object.field.get_width(); ++x) {
            Cell& tmp_cell = game_object.field.get_cell(y, x);

            bool passability = *reinterpret_cast<const bool *>(content.substr(0, sizeof(bool)).c_str());
            tmp_cell.set_passability(passability);
            content = content.substr(sizeof(bool));

            tmp_cell.set_event(generate_event.generate_event(content));
        }
    }

    game_object.player.set_life(*reinterpret_cast<const unsigned *>(content.substr(0, sizeof(unsigned)).c_str()));
    content = content.substr(sizeof(unsigned));
    game_object.player.set_double_jump(*reinterpret_cast<const unsigned *>(content.substr(0, sizeof(unsigned)).c_str()));
    content = content.substr(sizeof(unsigned));

    unsigned x = *reinterpret_cast<const unsigned *>(content.substr(0, sizeof(unsigned)).c_str());
    content = content.substr(sizeof(unsigned));
    unsigned y = *reinterpret_cast<const unsigned *>(content.substr(0, sizeof(unsigned)).c_str());
    content = content.substr(sizeof(unsigned));

    Manage m(game_object.player, game_object.field, { x, y });
    game_object.manage = std::move(m);

    game_object.group_enemy.clear();

    unsigned n = *reinterpret_cast<const size_t *>(content.substr(0, sizeof(unsigned)).c_str());
    content = content.substr(sizeof(unsigned));
    for (unsigned i = 0; i < n; ++i) {
        unsigned x = *reinterpret_cast<const unsigned *>(content.substr(0, sizeof(unsigned)).c_str());
        content = content.substr(sizeof(unsigned));
        unsigned y = *reinterpret_cast<const unsigned *>(content.substr(0, sizeof(unsigned)).c_str());
        content = content.substr(sizeof(unsigned));
        size_t id = *reinterpret_cast<const size_t *>(content.substr(0, sizeof(size_t)).c_str());
        content = content.substr(sizeof(size_t));
        if (id == typeid(GroupEnemy::Model<Enemy<SchemeMoveWall, SchemeAttackPlayer>>).hash_code()) {
            Enemy enemy(SchemeMoveWall(game_object.field, {x, y}),
                  SchemeAttackPlayer(game_object.manage),
                  "../sprite/ghost.png");
            game_object.group_enemy.add(enemy);
        }
    }


    return true;
}

bool GenerateLevel::restart() { return this->generate(this->order_level); }

bool GenerateLevel::next_level() {
    ++this->order_level;
    return this->generate(this->order_level);
}
