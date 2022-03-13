#pragma once
#include <iostream>
#include "SFML/Graphics.hpp"
#include "Frog.h"
#include "Level.h"
#include "Truck.h"
#include "Log.h"
#include "LilyPad.h"
#include "DeathZone.h"
#include "HUD.h"
#include "Collision.h"

class GameState
{
public:

	GameState();

private:

	sf::Clock spawner;
	sf::Clock spawner2;

	int wins = 0;
	int lives = 3;
	bool win = false;
	bool loss = false;
};

