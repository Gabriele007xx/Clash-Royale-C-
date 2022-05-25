#include "Button.h"

Button::Button(float x, float y, float width, float height, std::string text, sf::Font* font, sf::Color idlec, sf::Color hoverc, sf::Color activec, sf::Color text_i_color, sf::Color text_h_color, sf::Color text_a_color,unsigned char_s)
{
	this->buttonState = IDLE;
	this->shape.setPosition(sf::Vector2f(x, y));
	this->shape.setSize(sf::Vector2f(width, height));
	this->font = font;
	this->text.setFont(*this->font);
	this->text.setString(text);
	this->text.setFillColor(text_i_color);
	this->text.setCharacterSize(char_s);
	this->text.setPosition(this->shape.getPosition().x + (this->shape.getGlobalBounds().width / 2.f ) - this->text.getGlobalBounds().width / 2.f, 
							this->shape.getPosition().y + (this->shape.getGlobalBounds().height / 2.f) - this->text.getGlobalBounds().height / 2.f);
	this->idlec = idlec;
	
	this->hoverc = hoverc;
	this->activec = activec;
	this->text_a_c = text_a_color;
	this->text_h_c = text_h_color;
	this->text_idle_c = text_i_color;
	this->shape.setFillColor(this->idlec);



}

Button::~Button()
{
}

void Button::render(sf::RenderTarget* target)
{
	target->draw(this->shape);
	target->draw(this->text);
}
const bool Button::isPressed() const
{
	if (this->buttonState == ACTIVE)
	{
		return true;
	}
	return false;
}
void Button::update(const sf::Vector2f mousePos)
{
	this->buttonState = IDLE;
	if (this->shape.getGlobalBounds().contains(mousePos))
	{
		this->buttonState = HOVER;
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			this->buttonState = ACTIVE;
		}
	}
	switch (this->buttonState)
	{
	case IDLE:
		this->shape.setFillColor(this->idlec);
		this->text.setFillColor(this->text_idle_c);
		break;
	case HOVER:
		this->shape.setFillColor(this->hoverc);
		this->text.setFillColor(this->text_h_c);
		break;
	case ACTIVE:
		this->shape.setFillColor(this->activec);
		this->text.setFillColor(this->text_a_c);
		break;
	default:
		this->shape.setFillColor(sf::Color::Red);
		this->text.setFillColor(this->text_h_c);
		break;
	}
}
