#pragma once
#include <iostream>
#include "SFML/Graphics.hpp"
#include "Definitions.h"

class Truck
{
public:

	Truck(sf::Vector2u window, float x, float y);

	void MovementType1(sf::Event event);

	void MovementType2(sf::Event event);

	void Draw(sf::RenderWindow& window);

	sf::Sprite getTruck();

private:

	sf::Sprite truck;
	sf::Texture truckTex;

	sf::Clock spawn;
};

