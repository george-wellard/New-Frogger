#include <iostream>
#include "SFML/Graphics.hpp"
#include "Frog.h"
#include "Level.h"
#include "Truck.h"
#include "Log.h"
#include "LilyPad.h"
#include "DeathZone.h"
#include "Collision.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode(640, 480), "Frogger");
	const int iPad = 5;
	int wins = 0;
	int lives = 3;

	Frog frog(window.getSize());
	Level level(window.getSize());
	Truck truck(window.getSize(), 0, 270);
	Truck truck2(window.getSize(), 0, 360);
	Log log(window.getSize(), 0, 80);
	Log log2(window.getSize(), 0, 130);
	LilyPad lilypad [iPad];
	DeathZone water(window.getSize());
	Collision collision;

	lilypad[0].setPos(40, 0);
	lilypad[1].setPos(160, 0);
	lilypad[2].setPos(280, 0);
	lilypad[3].setPos(400, 0);
	lilypad[4].setPos(520, 0);

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
			lives--;
			frog.Respawn(window.getSize());
		}

		if (collision.TruckFrogCollision(truck2.getTruck(), frog.getFrog()))
		{
			lives--;
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

		for (int i = 0; i < iPad; i++)
		{
			if (collision.WaterFrogCollision(water.getDeathZone(), frog.getFrog()) &&
				!collision.LogFrogCollision(log.getLog(), frog.getFrog()) &&
				!collision.LogFrogCollision(log2.getLog(), frog.getFrog()) &&
				!collision.PadFrogCollision(lilypad[i].getLilyPad(), frog.getFrog()))
			{
				lives--;
				frog.Respawn(window.getSize());
			}

			if (collision.PadFrogCollision(lilypad[i].getLilyPad(), frog.getFrog()))
			{
				lilypad[i].addFrog();
				wins++;
				frog.Respawn(window.getSize());
			}
		}

		if (wins == 5)
		{
			std::cout << "You Win!" << std::endl;
		}

		if (lives == 0)
		{
			std::cout << "Game Over!" << std::endl;
		}

		level.Draw(window);
		water.Draw(window);
		for (int i = 0; i < iPad; i++)
		{
			lilypad[i].Draw(window);
		}
		log.Draw(window);
		log2.Draw(window);
		frog.Draw(window);
		truck.Draw(window);
		truck2.Draw(window);

		window.display();

	}

	return EXIT_SUCCESS;
}