#pragma once
#include <SFML/Graphics.hpp>
#include "Player.h"
#include "Obstacle.h"
#include <iostream>

bool CheckCollison(Player p1, Obstacle p2)
{
	if (p1.player_shape.getGlobalBounds().intersects(p2.obstacle.getGlobalBounds()))
		return true;
	
	return false;
}
