#ifndef generate_event_h
#define generate_event_h

#include "event_change_field.h"
#include "event_change_xp.h"
#include "event_jump.h"
#include "Object/Field/field.h"
#include "Object/Player/player.h"

class GenerateEvent {

    Field& field;
    Player& player;

    IEvent* generate_event_change_field(std::string&);
    IEvent* generate_event_change_xp(std::string&);
    IEvent* generate_event_jump(std::string&); 
    IEvent* generate_null_event(std::string&); 

public:

    GenerateEvent(Field&, Player&);

    IEvent* generate_event(std::string&);

};

#endif