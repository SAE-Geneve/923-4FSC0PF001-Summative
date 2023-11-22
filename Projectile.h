#pragma once
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

class Projectile
{
	sf::RectangleShape shape_;

	bool is_exploded_ = false;
	sf::Vector2f speed_;

public:
	Projectile(float x, float y, sf::Vector2f speed);

	sf::FloatRect GetBounds() { return shape_.getGlobalBounds(); }

	void Draw(sf::RenderWindow& window_);
	void Move();

	void Explode();
	bool IsExpoded();
	bool IsOutOfWindow();

};

