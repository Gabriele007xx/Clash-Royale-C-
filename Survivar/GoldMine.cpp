#include "GoldMine.h"

GoldMine::GoldMine()
{
	this->max_hitpoints = 400;
	this->current_hitpoints = max_hitpoints;
	this->max_lvl = 14;
	this->max_stored_res = 1000;
	this->stored_Resources = 0;
	this->resource_producted = Resources::GOLD;
	this->produciont_rate = 200;
	this->cost = 150;
	this->res_c = Resources::ELIXIR;
	building_texture.loadFromFile("Assets/graphics/buildings/gold_mine.png");
	b_s.setTexture(building_texture);
	b_s.setOrigin(building_texture.getSize().x/2,building_texture.getSize().y/2);
}

void GoldMine::tick()
{

}
void GoldMine::MoveToStarterLocation()
{
	sf::Vector2f position = sf::Vector2f(500.f, 696 / 2);
	b_s.setPosition(position);
}


