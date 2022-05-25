#pragma once
#include <sstream>
#include "SFML-2.5.1/include/SFML/Graphics.hpp"
#include "SFML-2.5.1/include/SFML/System.hpp"
#include "SFML-2.5.1/include/SFML/Window.hpp"
#include "SFML-2.5.1/include/SFML/Audio.hpp"
#include <stack>
#include<iostream>
#include<ctime>
#include<cstdlib>
enum button_states {
	IDLE = 0,
	HOVER,
	ACTIVE
};
class Button
{
private:
	sf::RectangleShape shape;
	sf::Font* font;
	sf::Text text;

	sf::Color text_idle_c;
	sf::Color text_a_c;
	sf::Color text_h_c;
	
	sf::Color idlec;
	sf::Color hoverc;
	sf::Color activec;

	short unsigned buttonState;
	
public:
	Button(float x, float y, float width, float height, std::string text, sf::Font* font, sf::Color idlec, sf::Color hoverc, sf::Color activec, sf::Color text_i_color, sf::Color text_h_color, sf::Color text_a_color, unsigned charsize);
	~Button();
	void render(sf::RenderTarget* target);
	void update(const sf::Vector2f mousePos);
	const bool isPressed() const;

};

