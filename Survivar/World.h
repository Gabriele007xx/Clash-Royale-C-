#pragma once
#include "SFML-2.5.1/include/SFML/Graphics.hpp"
class World
{
public:
	World();
	~World();
	void init(std::string tex);
	sf::Sprite getSprite();
private:
	const int TILE_LEGHT = 61;
	sf::Texture background;
	sf::Sprite bg;
};

