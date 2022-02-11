#include "Log.h"

Log::Log(sf::Vector2u size, float x, float y)
{
	logTex.loadFromFile(LOG_SPRITE_FILEPATH);
	log.setTexture(logTex);
	log.setPosition(x, y);

}

void Log::MovementType1(sf::Event event)
{
	sf::Clock spawn;

	log.move(0.25f, 0.0f);

	if (log.getPosition().x > 640)
	{
		log.setPosition(-150, 70);
	}
}

void Log::MovementType2(sf::Event event)
{
	sf::Clock spawn;

	log.move(-0.25f, 0.0f);

	if (log.getPosition().x < -100)
	{
		log.setPosition(680, 130);
	}
}

void Log::Draw(sf::RenderWindow &window)
{
	window.draw(log);
}

sf::Sprite Log::getLog()
{
	return log;
}
