#ifndef file_manager_h
#define file_manager_h

#include <string>
#include "Player/manage.h"


class FileMahager {

public:

    bool write_bin(const std::string&, Field&, Player&, Manage&);

    bool read_bin(const std::string&, Field&, Player&, Manage&);

    bool write_bin(const std::string&, std::string);

    bool read_bin(const std::string&, std::string&);

};

#endif