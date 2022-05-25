#include "GameState.h"


void GameState::initKeybinds()
{
	std::ifstream ifs("Config/games_keybind.ini");
	if (ifs.is_open())
	{
		std::string key = "";
		int key_val = 0;
		while (ifs >> key >> key_val)
		{
			this->keybinds[key] = key_val;
		}
	}


}

void GameState::initTe()
{
	if(this->textures["PLAYER_IDLE"].loadFromFile("Assets/graphics/Player_0.png"));
	if (this->textures["GIANT"].loadFromFile("Assets/graphics/troops/giant/giant_1.png"));
	if (this->textures["GIANT_CARD"].loadFromFile("Assets/graphics/card/giant.png"));
}

void GameState::initPl()
{
	this->player = new Player(0, 0, this->textures["PLAYER_IDLE"]);
}


GameState::GameState(sf::RenderWindow* window, std::map<std::string, int>* supportedkeys, std::stack<State*>* state_s) : State(window, supportedkeys, state_s)
{
	this->current_elixir = this->start_elixir;
	elixir_bar.restart();
	this->initKeybinds();
	this->initTe();
	this->initPl();
	this->elixir_b.setSize(sf::Vector2f(100.f,20.f));
	this->elixir_b.setFillColor(sf::Color::Black);
	this->current_e_b.setFillColor(sf::Color::Magenta);
	this->elixir_b.setPosition(window->getSize().x / 2, window->getSize().y - 20);
	this->current_e_b.setPosition(window->getSize().x / 2, window->getSize().y - 20);
	this->e.setPosition(window->getSize().x / 2 - 20, window->getSize().y - 20);
	e.setCharacterSize(12);
	this->bg.setFillColor(sf::Color::Blue);
	this->bg.setPosition(window->getSize().x / 2 - 35, window->getSize().y - 35);
	this->bg.setSize(sf::Vector2f(148, 35));
	font.loadFromFile("Assets/Fonts/supercell-magic.ttf");
	e.setFont(font);
	giant_card.setTexture(this->textures["GIANT_CARD"]);
	giant_card.setPosition(sf::Vector2f(window->getSize().x / 2,window->getSize().y - 53));
	
}

GameState::~GameState()
{
	delete this->player;
}

void GameState::updateInput(const float& dt)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape))
	{
		this->endState();
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		this->player->move(dt, -1.f, 0.f);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		this->player->move(dt, 1.f, 0.f);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		this->player->move(dt, 0.f, -1.f);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		this->player->move(dt, 0.f, 1.f);
	}
	
}

void GameState::update(const float& dt)
{
	if (elixir_bar.getElapsedTime().asSeconds() >= 0.24f && current_elixir < 10)
	{
		elixir_bar.restart();
		current_elixir = current_elixir + 0.1f;
	}
	if (this->giant_card.getGlobalBounds().contains(this->mousePosView))
	{
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			this->mouse_pressed = true;
			this->current_t = GIANT;
		}
	}
	this->e.setString(std::to_string((int)current_elixir));
	this->current_e_b.setSize(sf::Vector2f(this->current_elixir * 10, 20.f));
	this->updateMousePositions();
	this->updateInput(dt);
	this->placeCard(this->mousePosView);
	this->player->tick(dt);
	for (auto& it : this->troops)
	{
		it.tick();
	}
}

void GameState::render(sf::RenderTarget* target)
{
	if (!target)
	{
		target = this->window;
	}
	target->draw(bg);
	this->player->render(target);
	target->draw(elixir_b);
	target->draw(current_e_b);
	target->draw(e);
	target->draw(giant_card);
	for (auto& it : this->troops)
	{
		it.render(target);
	}
	
}
void GameState::placeCard(sf::Vector2f pos)
{
	if (this->current_t != NONE && sf::Mouse::isButtonPressed(sf::Mouse::Button::Left) && this->CanDrop)
	{
		switch (current_t)
		{
		case GIANT:
			if(current_elixir >= 5)
			{
				Giant giant = Giant(this->textures["GIANT"], 4091, 254, 1.2f, 1.5f);
				giant.setPos(pos.x, pos.y);
				
				this->troops.push_back(giant);
				this->current_t = NONE;
				this->CanDrop = false;
				this->current_elixir -= 5;
			}
			break;
		}
		
	}
}
