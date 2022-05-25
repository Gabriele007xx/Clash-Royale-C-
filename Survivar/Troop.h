#pragma once
#include "Entity.h"
class Troop :
    public Entity
{
protected:
    int MAX_HP;
    int CURENT_HP;
    float speed;
    int Damage;
    float range;
    int attack_speed;
    sf::RectangleShape healtBar;
    sf::RectangleShape bar;
    int t_width;
    int t_height;
public:
    Troop();
    Troop(sf::Texture tex);
    ~Troop();
    void tick();
    void onDeath();
    void attack();
    void DrawHealthBar();
    int getMaxHP();
    int getCurrentHP();
    float getSpeed();
    void render(sf::RenderTarget* target);

};

