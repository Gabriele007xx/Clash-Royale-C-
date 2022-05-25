#include "MainMenuState.h"


void MainMenuState::initKeybinds()
{
	


}

void MainMenuState::initFont()
{
	if (this->font.loadFromFile("Assets/Fonts/MinecraftRegular-Bmg3.otf"));
}

MainMenuState::MainMenuState(sf::RenderWindow* window, std::map<std::string, int>* supportedkeys, std::stack<State*>* state_s) : State(window, supportedkeys, state_s)
{
	this->intbg();
	this->initvariable();

	this->initFont();
	this->initKeybinds();
	this->initButtons();
}

MainMenuState::~MainMenuState()
{
	auto it = this->mainbutton.begin();
	for (it = this->mainbutton.begin();it != this->mainbutton.end();++it)
	{
		delete it->second;
	}
}

void MainMenuState::updateInput(const float& dt)
{
	
}

void MainMenuState::update(const float& dt)
{
	this->updateMousePositions();
	this->updateInput(dt);
	this->updateTheButtons();
}

void MainMenuState::render(sf::RenderTarget* target)
{
	if (!target)
	{
		target = this->window;
	}
	target->draw(this->bg);
	renderTheButtons(target);
}

void MainMenuState::updateTheButtons()
{
	for(auto &it : this->mainbutton)
	{
		it.second->update(this->mousePosView);
	}
	if (this->mainbutton["START"]->isPressed())
	{
		this->state_s->push(new GameState(this->window, this->supportedkeys, this->state_s));
	}
	if (this->mainbutton["EXIT"]->isPressed())
	{
		this->endState();
	}
}

void MainMenuState::renderTheButtons(sf::RenderTarget* target)
{
	for (auto& it : this->mainbutton)
	{
		it.second->render(target);
	}
}

void MainMenuState::initvariable()
{

}

void MainMenuState::intbg()
{
	this->bg.setSize(sf::Vector2f(static_cast<float>(this->window->getSize().x), static_cast<float>(this->window->getSize().y)));
	this->bg_tex.loadFromFile("Assets/graphics/bg/bg.png");
	this->bg.setTexture(&this->bg_tex);
}

void MainMenuState::initButtons()
{
	this->mainbutton["START"] = new Button(100, 100, 150, 50, "Start", &this->font, sf::Color::White, sf::Color::Cyan, sf::Color::Blue,sf::Color::White,sf::Color::White,sf::Color::Yellow,12);
	this->mainbutton["EDITOR"] = new Button(100, 300, 150, 50, "Editor", &this->font, sf::Color::White, sf::Color::Cyan, sf::Color::Blue, sf::Color::White, sf::Color::White, sf::Color::Yellow, 12);
	this->mainbutton["EXIT"] = new Button(100, 500, 150, 50, "Exit", &this->font, sf::Color::White, sf::Color::Cyan, sf::Color::Blue, sf::Color::White, sf::Color::White, sf::Color::Yellow, 12);
}

