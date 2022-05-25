#include "Entity.h"

Entity::Entity()
{
	this->initVar();
}

Entity::~Entity()
{
}

void Entity::move(const float& dt,const float dirx, const float diry)
{
	if (this->MovementComp)
	{
		this->MovementComp->move(dirx, diry, dt);
		
	}
}

void Entity::tick(const float& dt)
{
	if (this->MovementComp)
	{
		this->MovementComp->update(dt);
	}
}

void Entity::render(sf::RenderTarget* target)
{
		target->draw(this->sprite);
	
}

void Entity::setTex(sf::Texture& texture)
{
	this->sprite.setTexture(texture);
	
}

void Entity::setPos(const float x, const float y)
{
		this->sprite.setPosition(x, y);	
}

void Entity::CreateMoveC(const float maxSpeed, const float acc, const float d)
{
	this->MovementComp = new MoveCompoment(this->sprite,maxSpeed,acc,d);
}

void Entity::initVar()
{
	this->MovementComp = NULL;
}
