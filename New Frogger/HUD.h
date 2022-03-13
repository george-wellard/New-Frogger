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

	void Time(sf::RenderWindow& window);

	void UpdateLives(int lives);

	void UpdateTime(sf::Clock time);

private:

	sf::Text livesText;
	sf::Text winText;
	sf::Text loseText;
	sf::Text timeText;
	sf::Font font;

	sf::Clock timer;
};

