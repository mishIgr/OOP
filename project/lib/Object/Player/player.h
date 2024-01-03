#ifndef player_h
#define player_h

class Player {

    unsigned counter_life;
    unsigned counter_double_jump;
    unsigned invulnerability;
    
public:

    Player();
    Player(unsigned, unsigned);

    unsigned get_life() const;
    void set_life(unsigned);
    bool is_alive() const;

    unsigned get_double_jump() const;
    void set_double_jump(unsigned);

    unsigned get_invulnerability() const;
    void set_invulnerability(unsigned);

};

#endif