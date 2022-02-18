#include "LilyPad.h"

LilyPad::LilyPad()
{
	lilyPadTex.loadFromFile(LILYPAD_SPRITE_FILEPATH);
	lilyPad.setTexture(lilyPadTex);
}

void LilyPad::setPos(float x, float y)
{
	lilyPad.setPosition(x, y);
}

void LilyPad::addFrog()
{
	withFrogTex.loadFromFile(FROGPAD_SPRITE_FILEPATH);
	lilyPad.setTexture(withFrogTex);
}

void LilyPad::Draw(sf::RenderWindow& window)
{
	window.draw(lilyPad);
}

sf::Sprite LilyPad::getLilyPad()
{
	return lilyPad;
}
