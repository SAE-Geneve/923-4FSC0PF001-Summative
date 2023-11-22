#pragma once

#include "SFML/Graphics.hpp"


class Game
{

	// Const values
	const float kPlayerAltitude = 650;
	const sf::Vector2f kProjectilesSpeed = { 0, -32.45636365 };

	// Temporary player position
	float player_position = 0;

	sf::RenderWindow window_;
	sf::Clock clock_projectiles_;

	// Ennemies
	std::vector<sf::RectangleShape> invaders;
	// Projectiles
	std::vector<sf::RectangleShape> projectiles;
	// Player
	sf::CircleShape player;

	

public:
	void Setup();
	void Loop();

};

