#pragma once
#include "Troop.h"
class Giant :
    public Troop
{
public:
    Giant(sf::Texture& tex, int maxHP, int damage,float ATTK_r, float attack_s);
    Giant();
    ~Giant();
    void tick();
    void onDeath();
    void attack(Entity e);
    void initComp();
    void DrawHealthBar();
};

