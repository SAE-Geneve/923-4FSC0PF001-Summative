#pragma once
#include <SFML/Graphics.hpp>

class Invader
{

	sf::RectangleShape shape_;

public:
	Invader(float x, float y);
	void Draw(sf::RenderWindow& window_);

	sf::RectangleShape& GetShape() { return shape_; };
};

