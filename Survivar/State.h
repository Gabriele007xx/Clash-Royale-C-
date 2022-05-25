#pragma once
#include "Player.h"
class State
{
protected:
	sf::RenderWindow* window;
	std::map<std::string, sf::Texture> textures;
	bool quit;
	std::map<std::string, int>* supportedkeys;
	std::map<std::string, int> keybinds;
	sf::Vector2i mousePosScreen;
	sf::Vector2i mousePosWindow;
	sf::Vector2f mousePosView;
	std::stack<State*>* state_s;
	virtual void initKeybinds() = 0;
	bool mouse_pressed = false;
	bool CanDrop = false;
public:

	State(sf::RenderWindow* window, std::map<std::string, int>* supportedkeys, std::stack<State*>* state_s);
	virtual ~State();
	virtual void updateInput(const float& dt) = 0;
	virtual void update(const float& dt) = 0;
	virtual void render(sf::RenderTarget* target = NULL) = 0;
	virtual void updateMousePositions();
	const bool& getQuit() const;
	void endState();
};

