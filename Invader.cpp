#include "Invader.h"

#include <stdbool.h>

Invader::Invader(float x, float y)
{
	shape_.setSize(sf::Vector2f(15, 15));
	// Define the projectiles
	shape_.setOrigin(7.5, 7.5);
	shape_.setPosition(sf::Vector2f(x, y));
	shape_.setFillColor(sf::Color::Red);

	if (rand() % 2 == 0)
	{
		hp_ = 1;
	}
	else
	{
		hp_ = 3;
	}

}

void Invader::Draw(sf::RenderWindow& window)
{
	if(hp_ > 1)
	{
		shape_.setOutlineColor(sf::Color::White);
		shape_.setOutlineThickness(1);
	}else
	{
		shape_.setOutlineThickness(0);
	}

	window.draw(shape_);
}

void Invader::Hit()
{
	hp_--;
}

bool Invader::IsDead()
{
	return (hp_ <= 0);
}

bool Invader::IsColliding(const sf::FloatRect& rect)
{
	return shape_.getGlobalBounds().intersects(rect);
}

