#include "Player.h"

Player::Player(float x,float y,sf::Texture& texture)
{
    this->initVaria();
    this->initComp();
    this->setTex(texture);
    this->setPos(x, y);
}

Player::~Player()
{
}

int Player::getCurrentHealth()
{
    return this->CURRENT_H;
}

int Player::getMaxHealth()
{
    return this->MAX_HEALTH;
}

void Player::initVaria()
{
}

void Player::initComp()
{
    this->CreateMoveC(100.f,5.f,3.f);
}


