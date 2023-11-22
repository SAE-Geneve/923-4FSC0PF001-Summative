#include "Player.h"

#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

constexpr float kSmoothRatio = 0.15f;

void Player::Setup()
{
	// Player
	shape_ = sf::CircleShape(5, 3);
	shape_.setOrigin(2.5, 2.5);
	shape_.setPosition({ 640 , kPlayerAltitude });
	shape_.setFillColor(sf::Color(92, 88, 168));
	shape_.setOutlineColor(sf::Color::White);
	shape_.setOutlineThickness(1);

}

void Player::MoveX(float newX)
{
	shape_.setPosition(
			{ kSmoothRatio * newX + (1.F - kSmoothRatio) * shape_.getPosition().x,
				kPlayerAltitude
			}
		);
}

void Player::Draw(sf::RenderWindow& window)
{
	window.draw(shape_);
}
