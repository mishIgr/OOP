#ifndef file_manager_cpp
#define file_manager_cpp

#include <fstream>
#include <map>
#include <functional>
#include "File_manager/file_manager.h"
#include "Field/Event/generate_event.h"

bool FileMahager::write_bin(const std::string& file_name, Field &field, Player &player, Manage &manage)
{
    std::ofstream oFile(file_name, std::ios::binary);
    if (!oFile)
        return false;

    std::string output_str = "";

    unsigned tmp_u = field.get_width();
    output_str += std::string(reinterpret_cast<const char *>(&tmp_u), sizeof(tmp_u));
    tmp_u = field.get_height();
    output_str += std::string(reinterpret_cast<const char *>(&tmp_u), sizeof(tmp_u));

    for (size_t y = 0; y < field.get_height(); ++y) {
        for (size_t x = 0; x < field.get_width(); ++x) {
            Cell tmp_cell = field.get_cell(y, x);

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

    tmp_u = player.get_life();
    output_str += std::string(reinterpret_cast<const char *>(&tmp_u), sizeof(tmp_u));
    tmp_u = player.get_double_jump();
    output_str += std::string(reinterpret_cast<const char *>(&tmp_u), sizeof(tmp_u));

    for (size_t i = 0; i < 2; ++i) {
        tmp_u = manage.get_coord()[i];
        output_str += std::string(reinterpret_cast<const char *>(&tmp_u), sizeof(tmp_u));
    }

    std::hash<std::string> str_hash;

    size_t hash = str_hash(output_str);
    output_str = std::string(reinterpret_cast<const char *>(&hash), sizeof(hash)) + output_str;

    oFile << output_str;

    oFile.close();

    return true;
}

bool FileMahager::read_bin(const std::string& file_name, Field &field, Player &player, Manage &manage) {
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

    unsigned width = *reinterpret_cast<const unsigned *>(content.substr(0, sizeof(unsigned)).c_str());
    content = content.substr(sizeof(unsigned));
    unsigned height = *reinterpret_cast<const unsigned *>(content.substr(0, sizeof(unsigned)).c_str());
    content = content.substr(sizeof(unsigned));

    Field f(width, height);
    field = std::move(f);

    GenerateEvent generate_event(field, player);
    for (size_t y = 0; y < field.get_height(); ++y) {
        for (size_t x = 0; x < field.get_width(); ++x) {
            Cell& tmp_cell = field.get_cell(y, x);

            bool passability = *reinterpret_cast<const bool *>(content.substr(0, sizeof(bool)).c_str());
            tmp_cell.set_passability(passability);
            content = content.substr(sizeof(bool));

            tmp_cell.set_event(generate_event.generate_event(content));
        }
    }

    player.set_life(*reinterpret_cast<const unsigned *>(content.substr(0, sizeof(unsigned)).c_str()));
    content = content.substr(sizeof(unsigned));
    player.set_double_jump(*reinterpret_cast<const unsigned *>(content.substr(0, sizeof(unsigned)).c_str()));
    content = content.substr(sizeof(unsigned));

    unsigned x = *reinterpret_cast<const unsigned *>(content.substr(0, sizeof(unsigned)).c_str());
    content = content.substr(sizeof(unsigned));
    unsigned y = *reinterpret_cast<const unsigned *>(content.substr(0, sizeof(unsigned)).c_str());
    content = content.substr(sizeof(unsigned));

    Manage m(player, field, { x, y });
    manage = std::move(m);

    return true;
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