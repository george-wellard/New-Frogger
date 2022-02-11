#pragma once
#include <iostream>
#include "SFML/Graphics.hpp"
class DeathZone
{
public:

	DeathZone(sf::Vector2u size);

	void Draw(sf::RenderWindow &window);

	sf::RectangleShape getDeathZone();

private:

	sf::RectangleShape deathZone;
};

