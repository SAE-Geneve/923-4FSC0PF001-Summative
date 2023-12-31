#pragma once

#include "Invader.h"
#include "Player.h"
#include "Projectile.h"
#include "SFML/Graphics.hpp"


class Game
{

	// Const values
	const sf::Vector2f kProjectilesSpeed = { 0, -32.45636365f };

	// Temporary player position
	float player_position = 0;

	sf::RenderWindow window_;
	sf::Clock clock_projectiles_;

	// Ennemies
	std::vector<Invader> invaders_;
	// Projectiles
	std::vector<Projectile> projectiles;
	// Player
	Player player;

public:
	void Setup();
	void Loop();

};

