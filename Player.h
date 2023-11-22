#pragma once
#include <SFML/Graphics.hpp>

class Player
{
	const float kPlayerAltitude = 650;

	sf::CircleShape shape_;

public:
	void Setup();
	sf::Vector2f GetPosition() { return shape_.getPosition(); }
	void MoveX(float newX);
	void Draw(sf::RenderWindow& window);

};

