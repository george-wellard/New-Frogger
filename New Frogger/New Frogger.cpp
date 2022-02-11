#include <iostream>
#include "SFML/Graphics.hpp"
#include "Frog.h"
#include "Level.h"
#include "Truck.h"
#include "Log.h"
#include "DeathZone.h"
#include "Collision.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode(640, 480), "Frogger");
	sf::Font font;

	Frog frog(window.getSize());
	Level level(window.getSize());
	Truck truck(window.getSize(), 0, 270);
	Truck truck2(window.getSize(), 0, 360);
	Log log(window.getSize(), 0, 70);
	Log log2(window.getSize(), 0, 130);
	DeathZone water(window.getSize());
	Collision collision;

	while (window.isOpen())
	{
		sf::Event event;

		while (window.pollEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::Closed:
				window.close(); // Allowing the program to shut down once the window has been closed by the user

				break;

			case sf::Event::KeyReleased: // Checking for key releases 

				frog.Movement(event); // Declaring the Move function from the Frog Class

				break;
			}
		}

		window.clear();

		truck.MovementType1(event);
		truck2.MovementType2(event);
		log.MovementType1(event);
		log2.MovementType2(event);

		if (collision.TruckFrogCollision(truck.getTruck(), frog.getFrog()))
		{
			frog.Respawn(window.getSize());
		}

		if (collision.TruckFrogCollision(truck2.getTruck(), frog.getFrog()))
		{
			frog.Respawn(window.getSize());
		}

		if (collision.LogFrogCollision(log.getLog(), frog.getFrog()))
		{
			frog.LogMovement(event);
		}

		if (collision.LogFrogCollision(log2.getLog(), frog.getFrog()))
		{
			frog.LogMovementType2(event);
		}

		if (collision.WaterFrogCollision(water.getDeathZone(), frog.getFrog()) /* &&
			!collision.LogFrogCollision(log.getLog(), frog.getFrog()) &&
			!collision.LogFrogCollision(log2.getLog(), frog.getFrog())*/)
		{
			frog.Respawn(window.getSize());
		}

		//level.Draw(window);
		water.Draw(window);
		log.Draw(window);
		log2.Draw(window);
		frog.Draw(window);
		truck.Draw(window);
		truck2.Draw(window);

		window.display();

	}

	return EXIT_SUCCESS;
}