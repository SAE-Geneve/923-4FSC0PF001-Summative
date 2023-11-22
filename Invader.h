#pragma once
#include <SFML/Graphics.hpp>

class Invader
{
	sf::RectangleShape shape_;

	int hp_;

public:
	Invader(float x, float y);
	void Draw(sf::RenderWindow& window_);

	void Hit();

	bool IsDead();
	bool IsColliding(const sf::FloatRect& rect);

	//sf::RectangleShape& GetShape() { return shape_; };

};

