#include "Obstacle.h"
#include <iostream>
#include <SFML/Graphics.hpp>

Obstacle::Obstacle()
{
	obstacle.setSize(size);
	SetVelocity(velocity);

}

void Obstacle::Draw(sf::RenderWindow& window)
{
	window.draw(obstacle);
}

void Obstacle::SetPosition(sf::Vector2f position)
{
	obstacle.setPosition(position);
}

void Obstacle::SetVelocity(float vel)
{
	velocity = vel;
}

void Obstacle::Move(sf::Vector2f distance)
{
	obstacle.move(distance);
}

void Obstacle::SetOrigin(sf::Vector2f origin)
{
	obstacle.setOrigin(origin);
}

void Obstacle::UpdateScore()
{

	if (obstacle.getPosition().x < 0)
	{
		obstacle.setPosition(800, 800);
		score++;

		// std::cout << "Score: " << score << std::endl;
		printf("Score: %i\n", score);
	}

}

void Obstacle::Movement(float dt)
{
	UpdateScore();

	if (score != 0 && score % 5 == 0)
	{
		velocity += 50 * dt;
	}

	Move({-velocity * dt, 0});
}

sf::Vector2f Obstacle::GetSize()
{
	return obstacle.getSize();
}
