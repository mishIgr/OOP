//
// Created by mikhail on 21.12.23.
//

#ifndef PROJECT_ENEMY_H
#define PROJECT_ENEMY_H

#include "tuple.h"

template<typename SchemeMove, typename SchemeInteractionPlayer>
class Enemy {

    std::string loc_sprite;
    SchemeMove scheme_move;
    SchemeInteractionPlayer scheme_interaction_player;

public:

    Enemy(SchemeMove, SchemeInteractionPlayer, std::string);

    Tuple<unsigned> get_coord();
    bool move();
    bool interaction();
    std::string get_loc_sprite();

};

template<typename SchemeMove, typename SchemeInteractionPlayer>
Enemy<SchemeMove, SchemeInteractionPlayer>::Enemy(SchemeMove scheme_move, SchemeInteractionPlayer scheme_interaction_player, std::string loc_sprite) :
        scheme_move(scheme_move), scheme_interaction_player(scheme_interaction_player), loc_sprite(std::move(loc_sprite)) {}

template<typename SchemeMove, typename SchemeInteractionPlayer>
Tuple<unsigned> Enemy<SchemeMove, SchemeInteractionPlayer>::get_coord() { return scheme_move.get_position(); }

template<typename SchemeMove, typename SchemeInteractionPlayer>
bool Enemy<SchemeMove, SchemeInteractionPlayer>::move() { return scheme_move.move(); }

template<typename SchemeMove, typename SchemeInteractionPlayer>
bool Enemy<SchemeMove, SchemeInteractionPlayer>::interaction() { return scheme_interaction_player.interaction(); }

template<typename SchemeMove, typename SchemeInteractionPlayer>
std::string Enemy<SchemeMove, SchemeInteractionPlayer>::get_loc_sprite() { return this->loc_sprite; }

#endif //PROJECT_ENEMY_H
