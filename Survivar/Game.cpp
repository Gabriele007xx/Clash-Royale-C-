#include "Game.h"
Game::Game()
{
	init();
}

Game::~Game()
{
	delete this->window;
	while (!this->stati.empty())
	{
		delete this->stati.top();
	}
}
void Game::update()
{
	this->pollEvents();
	if (!this->stati.empty())
	{
		this->stati.top()->update(this->dt);
		if (this->stati.top()->getQuit())
		{
			this->stati.top()->endState();
			delete this->stati.top();
			this->stati.pop();
		}
	}
	else
	{
		this->window->close();
	}

}
void Game::render()
{
	this->window->clear();
	if (!this->stati.empty())
	{
		this->stati.top()->render();
	}
	//this->window->draw(world.getSprite());
	//this->window->draw(player.getSprite());
	this->window->display();
}
void Game::init()
{
	//Init basic objects
	//init window
	initWin();
	//init keybind
	initKeys();
	//init state
	initState();
}
const bool Game::running() const
{
	return this->window->isOpen();
}
void Game::pollEvents()
{
	while (this->window->pollEvent(this->evento))
	{
		switch (this->evento.type)
		{
		case sf::Event::Closed:
			this->window->close();
			break;
		}
	}
}
void Game::initKeys()
{
	std::ifstream i("Config/keybind.ini");
	if (i.is_open())
	{
		std::string key = "";
		int val = 0;
		while (i >> key >> val)
		{
			this->supportedkeys[key] = val;
		}
	}
	i.close();
}

void Game::initWin()
{
	std::fstream ifs("Config/window.ini");
	std::string title = "Null";
	sf::VideoMode window_bounds = sf::VideoMode::getDesktopMode();
	unsigned framerate_limit = 60;
	bool vs = false;
	this->VideoMds = sf::VideoMode::getFullscreenModes();
	bool fullscreen = false;
	unsigned antialiasing_power = 0;
	if (ifs.is_open())
	{
		std::getline(ifs, title);
		ifs >> window_bounds.width >> window_bounds.height;
		ifs >> fullscreen;
		ifs >> framerate_limit;
		ifs >> vs;
		ifs >> antialiasing_power;
	}
	ifs.close();

	this->fullscreen = fullscreen;
	this->ws.antialiasingLevel = antialiasing_power;
	
	if(fullscreen)
	{
		this->window = new sf::RenderWindow(window_bounds, title, sf::Style::Fullscreen, this->ws);
	}
	else
	{
		this->window = new sf::RenderWindow(window_bounds, title, sf::Style::Default, this->ws);
	}
	
	this->window->setFramerateLimit(framerate_limit);
	this->window->setVerticalSyncEnabled(vs);
}

void Game::updateDt()
{
	this->dt = this->dtclock.restart().asSeconds();
}

void Game::endApplication()
{

}

void Game::initState()
{
	this->stati.push(new MainMenuState(this->window, &this->supportedkeys, &this->stati));
}

void Game::initvar()
{
	this->window = NULL;
	this->dt = 0;
	fullscreen = false;
}

