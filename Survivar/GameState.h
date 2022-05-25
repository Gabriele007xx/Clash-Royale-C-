#pragma once
#include "State.h"
#include "Giant.h"
enum Troops
{
    NONE,
    GIANT
};
class GameState :
    public State
{
private:
    void initKeybinds();
    Player* player;
    void initTe();
    void initPl();
    std::vector<Troop> troops;
    sf::Clock elixir_bar;
    float start_elixir = 5;
    sf::RectangleShape elixir_b;
    sf::RectangleShape current_e_b;
    float current_elixir;
    sf::Text e;
    sf::Font font;
    sf::RectangleShape bg;
    sf::Sprite giant_card;
    Troops current_t = NONE;
public:
    GameState(sf::RenderWindow* window, std::map<std::string, int>* supportedkeys, std::stack<State*>* state_s);
    virtual ~GameState();
    void updateInput(const float& dt);
    void update(const float& dt);
    void render(sf::RenderTarget* target);
    void placeCard(sf::Vector2f position_mouse);
};

