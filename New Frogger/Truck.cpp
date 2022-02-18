#include "Truck.h"


Truck::Truck(sf::Vector2u window, float x, float y)
{
	truckTex.loadFromFile(TRUCK_SPRITE_FILEPATH);
	truck.setTexture(truckTex);
	truck.setPosition(x, y);
}

void Truck::MovementType1(sf::Event event)
{

	truck.move(0.20f, 0.0f);

	if (truck.getPosition().x > 640)
	{
		if (spawn.getElapsedTime().asSeconds() > SPAWN_TIME) {
			truck.setPosition(-150, 270);
			spawn.restart();
		}
	}
}

void Truck::MovementType2(sf::Event event)
{

	truck.move(-0.20f, 0.0f);

	if (truck.getPosition().x < -150)
	{
		if (spawn.getElapsedTime().asSeconds() > SPAWN_TIME) {
			truck.setPosition(680, 360);
			spawn.restart();
		}
	}
}

void Truck::Draw(sf::RenderWindow& window)
{
	window.draw(truck);
}

sf::Sprite Truck::getTruck()
{
	return truck;
}
