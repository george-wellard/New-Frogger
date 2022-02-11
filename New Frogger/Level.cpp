#include "Level.h"

Level::Level(sf::Vector2u size)
{
	levelTex.loadFromFile(LEVEL_SPRITE_FILEPATH);
	level.setTexture(levelTex);
	level.setPosition(0, 0);
}

void Level::Draw(sf::RenderWindow& window)
{
	window.draw(level);
}

sf::Sprite Level::getLevel()
{
	return sf::Sprite();
}
