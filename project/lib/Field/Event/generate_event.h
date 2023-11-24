#ifndef generate_event_h
#define generate_event_h

#include "Field/Event/event_change_field.h"
#include "Field/Event/event_change_xp.h"
#include "Field/Event/event_jump.h"
#include "Field/field.h"
#include "Player/player.h"

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