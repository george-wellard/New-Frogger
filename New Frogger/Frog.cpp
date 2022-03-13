#include "Frog.h"

Frog::Frog(sf::Vector2u size)
{
	frogTex.loadFromFile(FROG_SPRITE_FILEPATH);
	frog.setTexture(frogTex); // Setting the texture to the file that has just loaded
	frog.setPosition(sf::Vector2f(frog.getPosition().x + 20, size.y - frog.getScale().y / 2 - 60)); // Setting the position of the frog
	frog.setOrigin(frog.getGlobalBounds().width / 2, frog.getGlobalBounds().height / 2); // Centering the origin of the frog, so that when it rotates as it moves it remains centered instead of moving a distance away
}

void Frog::Movement(sf::Event event)
{
	if (sf::Keyboard::Key::Right == event.key.code)
	{
		frog.move(sf::Vector2f(50.0f, 0.0)); // Using the move function to make the frog move to the right
		frog.setRotation(0.0f); // Resetting the rotation to 0.0 so the frog rotation can 
		frog.rotate(90.0f); // Rotating the frog by 90 degrees, so it can face right
	}
	else if (sf::Keyboard::Key::Left == event.key.code)
	{
		frog.move(sf::Vector2f(-50.0f, 0.0));
		frog.setRotation(0.0f);
		frog.rotate(270.0f);
	}
	else if (sf::Keyboard::Key::Up == event.key.code)
	{
		frog.move(sf::Vector2f(0.0, -50.0f));
		frog.setRotation(0.0f);
		frog.rotate(0.0f);
	}
	else if (sf::Keyboard::Key::Down == event.key.code)
	{
		frog.move(sf::Vector2f(0.0, 50.0f));
		frog.setRotation(0.0f);
		frog.rotate(180.0f);
	}

	if (frog.getPosition().x < 0)
	{
		frog.move(50.0f, 0.0f);
	}

	if (frog.getPosition().x > 640)
	{
		frog.move(-50.0f, 0.0f);
	}

	if (frog.getPosition().y < 0)
	{
		frog.move(0.0f, 50.0f);
	}

	if (frog.getPosition().y > 480)
	{
		frog.move(0.0f, -50.0f);
	}
}

void Frog::LogMovement(sf::Event event)
{
	frog.move(0.15, 0);

	if (frog.getPosition().x > 640)
	{
		frog.move(-0.15, 0);
	}
}

void Frog::LogMovementType2(sf::Event event)
{
	frog.move(-0.15, 0);

	if (frog.getPosition().x < 0)
	{
		frog.move(0.15, 0);
	}
}

void Frog::Respawn(sf::Vector2u size)
{
	frog.setPosition(frog.getPosition().x + 20, size.y - frog.getScale().y / 2 - 60);
}

void Frog::Draw(sf::RenderWindow &window)
{
	window.draw(frog);
}

sf::Sprite Frog::getFrog()
{
	return frog;
}
