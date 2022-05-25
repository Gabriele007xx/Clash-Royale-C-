#include "SFML-2.5.1\include\SFML\Graphics.hpp"
#include "Game.h"
#include <vector>
int main()
{
	Game game = Game();
	while (game.running())
	{
		game.updateDt();
		game.pollEvents();
		game.update();
		game.render();
	}
	return 0;
}