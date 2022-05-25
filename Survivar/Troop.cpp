#include "Troop.h"

Troop::Troop()
{

}

Troop::Troop(sf::Texture tex)
{
}

Troop::~Troop()
{
}

void Troop::tick()
{
}

void Troop::onDeath()
{
}

void Troop::attack()
{
}

void Troop::DrawHealthBar()
{	
}

int Troop::getMaxHP()
{
	return this->MAX_HP;
}

int Troop::getCurrentHP()
{
	return this->CURENT_HP;
}

float Troop::getSpeed()
{
	return this->speed;
}
void Troop::render(sf::RenderTarget* target)
{
	target->draw(this->sprite);
	target->draw(this->healtBar);
	target->draw(this->bar);
}