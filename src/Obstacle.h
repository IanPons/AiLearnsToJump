#pragma once
#include <string>
#include <SFML/Graphics.hpp>

class Obstacle
{

public:
	Obstacle();

	void Draw(sf::RenderWindow& window);

	void Move(sf::Vector2f distance);

	void SetPosition(sf::Vector2f);

	void SetVelocity(float vel);

	void SetOrigin(sf::Vector2f origin);

	void Movement(float dt);

	void UpdateScore();

	sf::Vector2f GetSize();

	double getXPos() { return obstacle.getPosition().x; }

	double getVelocity() { return static_cast<double> (velocity); }
public:
	int score = 0;
	sf::RectangleShape obstacle;

private:
	sf::Vector2f size = {50, 50};
	float velocity = 400.0f;
};
