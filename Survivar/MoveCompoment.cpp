#include "MoveCompoment.h"

MoveCompoment::MoveCompoment(sf::Sprite& sprite, float maxSpeed, float acc,float dacc)
	: sprite(sprite), maxSpeed(maxSpeed), acc(acc), dacc(dacc)
{
}
MoveCompoment::~MoveCompoment()
{
}

void MoveCompoment::update(const float& dt)
{
	if (this->velocity.x > 0.f)
	{
		if (this->velocity.x > this->maxSpeed)
		{
			this->velocity.x = this->maxSpeed;
		}
		//Dacc x positive
		this->velocity.x -= dacc;

		if (this->velocity.x < 0.f)
		{
			this->velocity.x = 0.f;
		}
	}
	else if(this->velocity.x < 0.f)
	{
		if (this->velocity.x < -this->maxSpeed)
		{
			this->velocity.x = -this->maxSpeed;
		}
		this->velocity.x += dacc;
		if (this->velocity.x > 0.f)
		{
			this->velocity.x = 0.f;
		}
	}
	//Y
	if (this->velocity.y > 0.f)
	{
		if (this->velocity.y > this->maxSpeed)
		{
			this->velocity.y = this->maxSpeed;
		}
		//Dacc x positive
		this->velocity.y -= dacc;

		if (this->velocity.y < 0.f)
		{
			this->velocity.y = 0.f;
		}
	}
	else if (this->velocity.y < 0.f)
	{
		if (this->velocity.y < -this->maxSpeed)
		{
			this->velocity.y = -this->maxSpeed;
		}
		this->velocity.y += dacc;
		if (this->velocity.y > 0.f)
		{
			this->velocity.y = 0.f;
		}
	}
	
	this->sprite.move(this->velocity * dt);
}

void MoveCompoment::move(const float dirx, const float diry,const float dt)
{
	this->velocity.x += this->acc * dirx;

	
	this->velocity.y += this->acc * diry;

}

const sf::Vector2f& MoveCompoment::getVel() const
{
	return this->velocity;
}
