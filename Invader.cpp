#include "Invader.h"

Invader::Invader(float x, float y)
{

	shape_.setSize(sf::Vector2f(15, 15));
	// Define the projectiles
	shape_.setOrigin(7.5, 7.5);
	shape_.setPosition(sf::Vector2f(x, y));
	shape_.setFillColor(sf::Color::Yellow);

}

void Invader::Draw(sf::RenderWindow& window)
{
	window.draw(shape_);
}
