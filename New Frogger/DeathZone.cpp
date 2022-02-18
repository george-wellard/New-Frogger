#include "DeathZone.h"

DeathZone::DeathZone(sf::Vector2u size)
{
	deathZone.setPosition(0, 80);
	deathZone.setSize(sf::Vector2f(640, 100));
	deathZone.setFillColor(sf::Color::Blue);
}

void DeathZone::Draw(sf::RenderWindow& window)
{
	window.draw(deathZone);
}

sf::RectangleShape DeathZone::getDeathZone()
{
	return deathZone;
}
