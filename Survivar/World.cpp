#include "World.h"
#include "SFML-2.5.1\include\SFML\Graphics.hpp"
World::World()
{

}
World::~World()
{

}
void World::init(std::string t)
{
	background.loadFromFile(t);
	bg.setTexture(background);

}
sf::Sprite World::getSprite()
{
	return bg;
}

