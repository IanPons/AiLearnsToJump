#pragma once
#include <SFML/Graphics.hpp>

class Player
{
public:
	Player();

	void Draw(sf::RenderWindow& window);

	void Move(sf::Vector2f distance);

	void SetPos(sf::Vector2f newPos);

	void SetOrigin(sf::Vector2f origin);

	void Movement(float dt, std::vector<double> input);

	void LoadTexture(int row);

	void UpdateTexture(float dt, float switchtime, int row);


	sf::Vector2f getPos();

	sf::Vector2f getSize();

public:
	sf::RectangleShape player_shape;
	bool isJumping = false;


private:
	sf::Color player_color = sf::Color::Black;

	sf::Vector2f playerSize = { 100.0f, 150.0f };
	sf::Texture playerTexture;


	sf::Vector2u textureSize;
	int textureCount;
	float totalTime;

	const int ground = 800;
	const int jumpLimit = 650;
	float gravity = 300.0f;
	float moveSpeed = 400.0f;
};
