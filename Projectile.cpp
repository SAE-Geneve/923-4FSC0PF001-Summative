#include "Projectile.h"

Projectile::Projectile(float x, float y, sf::Vector2f speed)
{
	shape_.setSize({ 3, 60 });
	// Define the projectiles
	shape_.setOrigin(1.5, 5);
	shape_.setPosition(x, y);
	shape_.setFillColor(sf::Color::White);

	speed_ = speed;
}

void Projectile::Draw(sf::RenderWindow& window_)
{
	window_.draw(shape_);
}

void Projectile::Move()
{
	shape_.setPosition(shape_.getPosition() + speed_);
}

void Projectile::Explode()
{
	is_exploded_ = true;
}

bool Projectile::IsExpoded()
{
	return is_exploded_;
}

bool Projectile::IsOutOfWindow()
{
	return shape_.getPosition().y < 0;
}
