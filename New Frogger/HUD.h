#pragma once
#include <iostream>
#include "SFML/Graphics.hpp"
#include "Definitions.h"

class HUD
{
public:

	HUD();

	void Draw(sf::RenderWindow& window);

	void Win(sf::RenderWindow& window);

	void Lose(sf::RenderWindow& window);

	void Update(int lives);

private:

	sf::Text livesText;
	sf::Text winText;
	sf::Text loseText;
	sf::Font font;
};

