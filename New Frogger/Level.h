#pragma once
#include <iostream>
#include "SFML/Graphics.hpp"
#include "Definitions.h"

class Level
{
public:

	Level(sf::Vector2u size);

	void Draw(sf::RenderWindow& window);

	sf::Sprite getLevel();

private:

	sf::Sprite level;
	sf::Texture levelTex;
};

