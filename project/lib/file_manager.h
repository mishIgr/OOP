#ifndef file_manager_h
#define file_manager_h

#include <string>
#include "manage.h"
#include "event_change_field.h"
#include "event_jump.h"
#include "event_change_xp.h"

class FileMahager {

public:

    FileMahager();

    void write_bin(std::string, Field&, Player&, Manage&);

    void read_bin(std::string, Field&, Player&, Manage&);

};

#endif