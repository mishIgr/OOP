#ifndef file_manager_cpp
#define file_manager_cpp

#include <fstream>
#include <functional>
#include "File_manager/file_manager.h"
#include "Object/GroupEnemy/Enemy/enemy.h"
#include "Object/GroupEnemy/Enemy/Scheme/scheme_move_wall.h"
#include "Object/GroupEnemy/Enemy/Scheme/scheme_attack_player.h"
#include "Object/GroupEnemy/Enemy/Scheme/scheme_move.h"
#include "Object/GroupEnemy/Enemy/Scheme/scheme_push_player.h"

bool FileMahager::write_bin(const std::string& file_name, GameObject& game_object) {
    std::string output_str = "";

    unsigned tmp_u = game_object.field.get_width();
    output_str += std::string(reinterpret_cast<const char *>(&tmp_u), sizeof(tmp_u));
    tmp_u = game_object.field.get_height();
    output_str += std::string(reinterpret_cast<const char *>(&tmp_u), sizeof(tmp_u));

    for (size_t y = 0; y < game_object.field.get_height(); ++y) {
        for (size_t x = 0; x < game_object.field.get_width(); ++x) {
            Cell tmp_cell = game_object.field.get_cell(y, x);

            bool tmp_b = tmp_cell.is_passability();
            output_str += std::string(reinterpret_cast<const char *>(&tmp_b), sizeof(tmp_b));

            if (tmp_cell.get_event()) {
                output_str += tmp_cell.get_event()->get_str();
                continue;;
            }

            size_t tmp_t = 0;
            output_str += std::string(reinterpret_cast<const char *>(&tmp_t), sizeof(tmp_t));
        }
    }

    tmp_u = game_object.player.get_life();
    output_str += std::string(reinterpret_cast<const char *>(&tmp_u), sizeof(tmp_u));
    tmp_u = game_object.player.get_double_jump();
    output_str += std::string(reinterpret_cast<const char *>(&tmp_u), sizeof(tmp_u));

    for (size_t i = 0; i < 2; ++i) {
        tmp_u = game_object.manage.get_coord()[i];
        output_str += std::string(reinterpret_cast<const char *>(&tmp_u), sizeof(tmp_u));
    }

    tmp_u = game_object.group_enemy.size();
    output_str += std::string(reinterpret_cast<const char *>(&tmp_u), sizeof(tmp_u));
    for (const auto p : game_object.group_enemy) {
        tmp_u = p->get_coord()[0];
        output_str += std::string(reinterpret_cast<const char *>(&tmp_u), sizeof(tmp_u));
        tmp_u = p->get_coord()[1];
        output_str += std::string(reinterpret_cast<const char *>(&tmp_u), sizeof(tmp_u));
        size_t tmp_t = typeid(p.get()).hash_code();
        output_str += std::string(reinterpret_cast<const char *>(&tmp_t), sizeof(tmp_t));
    }

    return this->write_bin(file_name, output_str);
}

bool FileMahager::write_bin(const std::string& file_name, std::string output_str) {
    std::ofstream oFile(file_name, std::ios::binary);
    if (!oFile)
        return false;

    std::hash<std::string> str_hash;

    size_t hash = str_hash(output_str);
    output_str = std::string(reinterpret_cast<const char *>(&hash), sizeof(hash)) + output_str;

    oFile << output_str;

    oFile.close();
    return true;
}

bool FileMahager::read_bin(const std::string& file_name, std::string& input_str) {
    std::ifstream iFile(file_name, std::ios::binary);
    if (!iFile)
        return false;

    std::string content((std::istreambuf_iterator<char>(iFile)), std::istreambuf_iterator<char>());
    iFile.close();

    try {
        std::hash<std::string> str_hash;
        size_t hash = *reinterpret_cast<const size_t *>(content.substr(0, sizeof(size_t)).c_str());

        content = content.substr(sizeof(size_t));

        if (hash != str_hash(content))
            return false;
    }
    catch (std::out_of_range) {
        return false;
    }
    input_str = std::move(content);

    return true;
}

#endif