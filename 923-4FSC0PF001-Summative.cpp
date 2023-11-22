

#include <iostream>

#include "SFML/Graphics.hpp"

int main()
{
	sf::RenderWindow window(sf::VideoMode(1280, 720), "4FSC0PF001 - Summative exam");

	// Basic Setup of the window
	// Vertical sync, framerate
	window.setVerticalSyncEnabled(true);
	window.setFramerateLimit(30); // TO DO : bug the framerate

	// Constants
	constexpr float KInvaderMargin = 150;
	constexpr float KInvaderSpacing = 20;
	constexpr float kInvadersNbLines = 15;

	constexpr float kSmoothRatio = 0.15f;
	constexpr float kShootingRateAsSeconds = 0.15f;
	const float kPlayerAltitude = (float)window.getSize().y - 50;

	// Time ----------------------------------------------------------------------------------
	sf::Clock clock_projectiles_;


	// Game elements -------------------------------------------------------------------------
	// Ennemies
	std::vector<sf::RectangleShape> invaders;

	// Projectiles
	std::vector<sf::RectangleShape> projectiles;
	const sf::Vector2f kProjectilesSpeed = { 0, -32.45636365 };

	// Player
	sf::CircleShape player = sf::CircleShape(5, 3);
	player.setOrigin(2.5, 2.5);
	player.setPosition({ (float)window.getSize().x * 0.5f , kPlayerAltitude });
	player.setFillColor(sf::Color(92, 88, 168));
	player.setOutlineColor(sf::Color::White);
	player.setOutlineThickness(1);
	float player_position = 0;

	int steps_x = (int)std::floor(((float)window.getSize().x - 2.f * KInvaderMargin) / KInvaderSpacing);
	float invader_line_altitude = 0.5f * (float)window.getSize().y;

	for (int y = 0; y <= kInvadersNbLines; ++y)
	{
		for (int x = 0; x <= steps_x; ++x)
		{
			invaders.emplace_back(sf::RectangleShape({ 15, 15 }));
			// Define the projectiles
			invaders.back().setOrigin(7.5, 7.5);
			invaders.back().setPosition(KInvaderMargin + x * KInvaderSpacing, invader_line_altitude);
			invaders.back().setFillColor(sf::Color::Red);
		}

		invader_line_altitude -= KInvaderSpacing;

	}

	while (window.isOpen())
	{

		window.clear(sf::Color::Black);

		// Input controls and actions
		// Non events----------------------------------
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && clock_projectiles_.getElapsedTime().asSeconds() > kShootingRateAsSeconds)
		{
			projectiles.emplace_back(sf::RectangleShape({ 3, 60 }));
			// Define the projectiles
			projectiles.back().setOrigin(1.5, 5);
			projectiles.back().setPosition(player.getPosition().x, player.getPosition().y - 25);
			projectiles.back().setFillColor(sf::Color::White);

			// Reset timer
			clock_projectiles_.restart();
		}

		// Events -------------------------------------
		sf::Event event;
		while (window.pollEvent(event))
		{

			switch (event.type)
			{

			case sf::Event::MouseMoved:
				player_position = std::floor(event.mouseMove.x);
				break;

				// evenement "fermeture demandee" : on ferme la fenetre
			case sf::Event::Closed:
				window.close();
				break;

			default:
				break;
			}

		}

		// Game play frame ==================================================================================================================================
		// Move the player
		player.setPosition(
			{ kSmoothRatio * player_position + (1.F - kSmoothRatio) * player.getPosition().x,
				kPlayerAltitude
			}
		);

		// Move the projectiles
		for (auto& p : projectiles)
		{
			p.setPosition(p.getPosition() + kProjectilesSpeed);
		}
		// Clean the projectiles
		auto projectiles_it = std::remove_if(projectiles.begin(), projectiles.end(), [](sf::RectangleShape& p) {return p.getPosition().y < 0; });
		projectiles.erase(projectiles_it, projectiles.end());

		// KaBooom ?? ================================================================================================================================
		for (auto& i : invaders)
		{

			if (i.getFillColor() == sf::Color::Black)
				continue;

			for (auto& p : projectiles)
			{

				if (p.getFillColor() == sf::Color::Black)
					continue;

				if (i.getGlobalBounds().intersects(p.getGlobalBounds()))
				{
					// Boom ----------------------------------------------------------------------------
					p.setFillColor(sf::Color::Black);
					i.setFillColor(sf::Color::Black);
				}
			}
		}

		// Clean the projectiles
		auto projectiles_boomed_it = std::remove_if(projectiles.begin(), projectiles.end(), [](sf::RectangleShape& p) {return p.getFillColor() == sf::Color::Black; });
		projectiles.erase(projectiles_boomed_it, projectiles.end());

		// Clean the invaders
		auto invader_boomed_it = std::remove_if(invaders.begin(), invaders.end(), [](sf::RectangleShape& i) {return i.getFillColor() == sf::Color::Black; });
		invaders.erase(invader_boomed_it, invaders.end());

		//std::cout << "Projectiles remaining count " << projectiles.size() << std::endl;

		// Graphical frame ==================================================================================================================================
		for (auto& i : invaders)
		{
			window.draw(i);
		}
		for (auto& p : projectiles)
		{
			window.draw(p);
		}

		window.draw(player);

		window.display();

	}



}
