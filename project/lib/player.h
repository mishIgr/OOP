#ifndef player_h
#define player_h

class Player {

    unsigned counter_life;
    unsigned counter_double_jump;
    
public:

    Player();
    Player(unsigned, unsigned);

    unsigned get_life() const;
    void set_life(unsigned);
    bool is_alive() const;

    unsigned get_double_jump() const;
    void set_double_jump(unsigned);
};

#endif