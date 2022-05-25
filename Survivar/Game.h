#pragma once
#include "World.h"
#include "Player.h"
#include "MainMenuState.h"
class Game
{
private:
	World world;
	sf::RenderWindow* window;
	sf::Event evento;
	sf::Clock dtclock;
	float dt;
	std::stack<State*> stati;
	std::vector<sf::VideoMode> VideoMds;
	std::map<std::string, int> supportedkeys;
	sf::ContextSettings ws;
	bool fullscreen = false;
public:
	Game();
	virtual ~Game();
	const bool running() const;
	void update();
	void render();
	void init();
	void initWin();
	void initKeys();
	void initState();
	void pollEvents();
	void updateDt();
	void endApplication();
	void initvar();
};

