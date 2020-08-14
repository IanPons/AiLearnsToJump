#include "Player.h"
#include <iostream>

Player::Player()
{
    player_shape.setSize(playerSize);

    textureCount = 0;
    totalTime = 0;
    playerTexture.loadFromFile("./src/tux_from_linux.png");
    player_shape.setTexture(&playerTexture);

    textureSize = playerTexture.getSize();

    textureSize.x /= 3;
    textureSize.y /= 9;
    LoadTexture(0);
	//player_shape.setFillColor(player_color);
}

void Player::Draw(sf::RenderWindow& window)
{
	window.draw(player_shape);
}

void Player::Move(sf::Vector2f distance)
{
    player_shape.move(distance);
}

void Player::SetPos(sf::Vector2f newPos)
{
    player_shape.setPosition(newPos);
}

void Player::SetOrigin(sf::Vector2f origin)
{
    player_shape.setOrigin(origin);
}


void Player::Movement(float dt, std::vector<double> input)
{
    if (input[0] > 0 && getPos().y >= ground )
    {
      isJumping = true;
    }
    // if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && getPos().y >= ground)
    // if (input > 0 && getPos().y >= ground)
    // {
    //     isJumping = true;
    // }
    // else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && !isJumping)
    // {
    //     gravity += 50;
    // }
    // else {
    //     gravity = 300.0f;
    // }

    if (isJumping)
    {
        if (getPos().y <= jumpLimit)
        {
            isJumping = false;
        }
        else
        {
            Move({ 0.0f, -moveSpeed * dt });
        }
    }

    if (getPos().y < ground && isJumping == false)
    {
        Move({ 0.0f, gravity * dt });
    }
}

void Player::LoadTexture(int row)
{
    player_shape.setTextureRect(sf::IntRect(textureSize.x * row, textureSize.y * 0, textureSize.x, textureSize.y));
}

void Player::UpdateTexture(float dt, float switchtime, int row)
{
    totalTime += dt;

    if (totalTime >= switchtime)
    {
        totalTime -= switchtime;
        LoadTexture(textureCount);
        textureCount++;

        if (textureCount >= 3)
        {
            textureCount = 0;
        }
    }
}

sf::Vector2f Player::getPos()
{
	return player_shape.getPosition();
}

sf::Vector2f Player::getSize()
{
    return player_shape.getSize();
}
