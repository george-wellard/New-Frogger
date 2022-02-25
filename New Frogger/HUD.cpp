#include "HUD.h"

HUD::HUD()
{
	font.loadFromFile(LIFE_FONT_FILEPATH);
	livesText.setFont(font);
	winText.setFont(font);
	loseText.setFont(font);

	livesText.setString(std::string("3"));
	livesText.setCharacterSize(40);
	livesText.setFillColor(sf::Color::White);
	livesText.setPosition(500, 480);

	winText.setString(std::string("You win!"));
	winText.setCharacterSize(120);
	winText.setFillColor(sf::Color::White);
	winText.setPosition(50, 200);

	loseText.setString(std::string("Game Over!"));
	loseText.setCharacterSize(120);
	loseText.setFillColor(sf::Color::White);
	loseText.setPosition(50, 200);
}

void HUD::Draw(sf::RenderWindow& window)
{
	window.draw(livesText);
}

void HUD::Win(sf::RenderWindow& window)
{
	window.draw(winText);
}

void HUD::Lose(sf::RenderWindow& window)
{
	window.draw(loseText);
}

void HUD::Update(int lives)
{
	livesText.setString(std::to_string(lives));
}