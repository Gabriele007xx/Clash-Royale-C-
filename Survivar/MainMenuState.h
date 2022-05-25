#pragma once
#include "GameState.h"
#include "button.h"
class MainMenuState :
    public State
{
private:
    sf::RectangleShape bg;
    sf::Font font;
    std::map<std::string, Button*> mainbutton;
    void initKeybinds();
    void initFont();
    void initButtons();
    sf::Texture bg_tex;
public:
    MainMenuState(sf::RenderWindow* window, std::map<std::string, int>* supportedkeys, std::stack<State*>* state_s);
    ~MainMenuState();
    void updateInput(const float& dt);
    void update(const float& dt);
    void render(sf::RenderTarget* target);
    void updateTheButtons();
    void renderTheButtons(sf::RenderTarget* target);
    void initvariable();
    void intbg();
};

