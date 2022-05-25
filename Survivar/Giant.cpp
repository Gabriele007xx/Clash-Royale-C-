#include "Giant.h"

Giant::Giant(sf::Texture& tex, int maxHP, int damage, float ATTK_r, float attack_s)
{
	this->MAX_HP = maxHP;
	this->CURENT_HP = maxHP;
	this->Damage = damage;
	this->range = ATTK_r;
	this->attack_speed = attack_s;
	this->setTex(tex);
	this->texture_entity = tex;
	this->initComp();
	sprite.setOrigin(tex.getSize().x / 2, tex.getSize().y / 2);
}

Giant::Giant()
{
}

Giant::~Giant()
{
}

void Giant::tick()
{
	this->DrawHealthBar();
}

void Giant::onDeath()
{
}

void Giant::attack(Entity e)
{
}

void Giant::initComp()
{
	this->CreateMoveC(30.f, 0.f, 0.f);
}
void Giant::DrawHealthBar()
{
}
