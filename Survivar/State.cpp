#include "State.h"

State::State(sf::RenderWindow* window, std::map<std::string, int>* supportedkeys, std::stack<State*>* state_s)
{
	this->state_s = state_s;
	this->supportedkeys = supportedkeys;
	this->window = window;
	this->quit = false;
}

State::~State()
{

}

const bool& State::getQuit() const
{
	return this->quit;
}
void State::endState()
{
	this->quit = true;
}
void State::updateMousePositions()
{
	this->mousePosScreen = sf::Mouse::getPosition();
	this->mousePosWindow = sf::Mouse::getPosition(*this->window);
	this->mousePosView = this->window->mapPixelToCoords(sf::Mouse::getPosition(*this->window));
	if (!sf::Mouse::isButtonPressed(sf::Mouse::Button::Left) && this->mouse_pressed)
	{
		this->CanDrop = true;
		this->mouse_pressed = false;
	}
}
