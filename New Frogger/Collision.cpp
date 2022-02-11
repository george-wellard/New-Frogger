#include "Collision.h"

Collision::Collision()
{
}

bool Collision::TruckFrogCollision(sf::Sprite truck, sf::Sprite frog)
{
	sf::FloatRect frogRect = frog.getGlobalBounds();
	sf::FloatRect truckRect = truck.getGlobalBounds();

	if (frogRect.intersects(truckRect))
	{
		return true;
	}

	return false;
}

bool Collision::LogFrogCollision(sf::Sprite log, sf::Sprite frog)
{
	sf::FloatRect frogRect = frog.getGlobalBounds();
	sf::FloatRect logRect = log.getGlobalBounds();

	if (frogRect.intersects(logRect))
	{
		return true;
	}

	return false;
}

bool Collision::WaterFrogCollision(sf::RectangleShape water, sf::Sprite frog)
{
	sf::FloatRect frogRect = frog.getGlobalBounds();
	sf::FloatRect waterRect = water.getGlobalBounds();

	if (frogRect.intersects(waterRect))
	{
		return true;
	}

	return false;
}

