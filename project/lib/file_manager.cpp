#ifndef file_manager_cpp
#define file_manager_cpp

#include <iostream>
#include <fstream>
#include <bitset>
#include <functional>
#include "file_manager.h"

FileMahager::FileMahager() {}

void FileMahager::write_bin(std::string file_name, Field& field, Player& player, Manage& manage) {
    std::ofstream oFile(file_name, std::ios::binary);
    std::string output_str = "";

    unsigned tmp_u = field.get_width();
    output_str += std::string(reinterpret_cast<const char*>(&tmp_u), sizeof(tmp_u));
    tmp_u = field.get_height();
    output_str += std::string(reinterpret_cast<const char*>(&tmp_u), sizeof(tmp_u));

    for (size_t y = 0; y < field.get_height(); ++y) {
        for (size_t x = 0; x < field.get_width(); ++x) {
            Cell tmp_cell = field.get_cell(x, y);
            
            bool tmp_b = tmp_cell.is_passability();
            output_str += std::string(reinterpret_cast<const char*>(&tmp_b), sizeof(tmp_b));

            if (tmp_cell.get_event() == nullptr) {
                output_str += std::string(reinterpret_cast<const char*>(0), sizeof(char));
                break;
            }

            auto tmp_p = tmp_cell.get_event();
            char id = 0;
            if (typeid(*tmp_p) == typeid(EventJump)) {
                id = 1;
                oFile.write(reinterpret_cast<const char*>(&id), sizeof(id));
            }
            else if (typeid(tmp_p) == typeid(EventChangeXP*)) {
                id = 2;
                oFile.write(reinterpret_cast<const char*>(&id), sizeof(id));
            }
            else if (typeid(tmp_p) == typeid(EventChangeField*)) {
                id = 3;
                oFile.write(reinterpret_cast<const char*>(&id), sizeof(id));
            }


        }
    }
}

void FileMahager::read_bin(std::string, Field&, Player&, Manage&) {}

#endif