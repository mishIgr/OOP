#ifndef file_manager_h
#define file_manager_h

#include <string>
#include "Object/game_object.h"


class FileMahager {

public:

    bool write_bin(const std::string&, GameObject&);

    bool write_bin(const std::string&, std::string);

    bool read_bin(const std::string&, std::string&);

};

#endif