#pragma once
#include <iostream>
#include "Definitions.h"
#include "SFML/Graphics.hpp"

class LilyPad
{
public:

	LilyPad();

	void setPos(float x, float y);

	void addFrog();

	void Draw(sf::RenderWindow& window);

	sf::Sprite getLilyPad();

private:

	sf::Sprite lilyPad;
	sf::Texture lilyPadTex;
	sf::Texture withFrogTex;
};

