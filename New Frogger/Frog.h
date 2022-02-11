#pragma once

#include <iostream>
#include "SFML/Graphics.hpp"
#include "Definitions.h"

class Frog
{
public:

	Frog(sf::Vector2u size);

	void Movement(sf::Event event);

	void LogMovement(sf::Event event);

	void LogMovementType2(sf::Event event);

	void Respawn(sf::Vector2u size);

	void Draw(sf::RenderWindow &window);

	sf::Sprite getFrog();

private:

	sf::Sprite frog;
	sf::Texture frogTex;
};

