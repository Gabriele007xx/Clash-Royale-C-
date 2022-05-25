#pragma once
#include <vector>
#include <sstream>
#include "SFML-2.5.1/include/SFML/Graphics.hpp"
#include "SFML-2.5.1/include/SFML/System.hpp"
#include "SFML-2.5.1/include/SFML/Window.hpp"
#include "SFML-2.5.1/include/SFML/Audio.hpp"
#include <stack>
#include<fstream>
#include<map>
class MoveCompoment
{
private:
	float maxSpeed;
	sf::Vector2f velocity;
	float acc;
	float dacc;
	sf::Sprite& sprite;
public:
	MoveCompoment(sf::Sprite& sprite,float maxSpeed,float acc,float dacc);
	virtual ~MoveCompoment();

	void update(const float& dt);
	void move(const float x, const float y,const float dt);
	const sf::Vector2f& getVel() const;

};

