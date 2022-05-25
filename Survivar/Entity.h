#pragma once
#include "MoveCompoment.h"
class Entity
{
public:
	Entity();
	virtual ~Entity();

	virtual void move(const float& dt,const float x, const float y);
	virtual void tick(const float& dt);
	virtual void render(sf::RenderTarget* target);
	void setTex(sf::Texture& texture);
	virtual void setPos(const float x, const float y);
	void CreateMoveC(const float maxSpeed, const float acc, const float d);
protected:
	sf::Sprite sprite;
	sf::Texture texture_entity;
	MoveCompoment* MovementComp;
private:
	void initVar();
};

