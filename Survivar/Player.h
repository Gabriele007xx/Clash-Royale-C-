#pragma once
#include "Entity.h"
class Player : public Entity
{
public:
	Player(float x,float y,sf::Texture& texture);
	virtual ~Player();
	int getCurrentHealth();
	int getMaxHealth();
private:
	int MAX_HEALTH = 100;
	float CURRENT_H = 100;
	void initVaria();
	void initComp();
};

