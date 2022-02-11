#pragma once
#include "SFML/Graphics.hpp"
#include "Definitions.h"

class Log
{
public:

	Log(sf::Vector2u size, float x, float y);

	void MovementType1(sf::Event event);

	void MovementType2(sf::Event event);

	void Draw(sf::RenderWindow& window);

	sf::Sprite getLog();

private:

	sf::Sprite log;

	sf::Texture logTex;
};

