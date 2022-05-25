#pragma once
#include<map>
#include <string>
#include "SFML-2.5.1/include/SFML/Graphics.hpp"
#include "SFML-2.5.1/include/SFML/System.hpp"
#include "SFML-2.5.1/include/SFML/Window.hpp"
#include "SFML-2.5.1/include/SFML/Audio.hpp"
class AnimComponent
{
private:
	class Animation
	{
		public:
			sf::Texture& sheet;
			float Anims;
			int width;
			int height;
			sf::IntRect Srect;
			sf::IntRect EndRectagle;
			Animation(sf::Texture& tesheet, float speed, int start_x, int start_y, int end_y, int end_x, int width, int height)
			:	sheet(tesheet), Anims(speed), width(width), height(height)
			{
	
				this->Srect = sf::IntRect(start_x, start_y, width, height);
				this->EndRectagle = sf::IntRect(end_x, end_y, width, height);
			}
			void update(const float& dt);
			void pause();
			void reset();

	};
	std::map<std::string, Animation> anim;
public:
	AnimComponent();
	virtual ~AnimComponent();
};

