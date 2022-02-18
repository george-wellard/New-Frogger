#pragma once
#include <iostream>
#include "SFML/Graphics.hpp"
#include "Frog.h"
#include "Truck.h"
#include "Log.h"

class Collision
{
public:

	Collision();

	bool TruckFrogCollision(sf::Sprite truck, sf::Sprite frog);

	bool LogFrogCollision(sf::Sprite log, sf::Sprite frog);

	bool WaterFrogCollision(sf::RectangleShape water, sf::Sprite frog);

	bool PadFrogCollision(sf::Sprite pad, sf::Sprite frog);

};

