#pragma once
#include <random>

double generateRandomDouble(std::mt19937 &rng, int min, int max)
{
	std::uniform_real_distribution<double> urd(min, max);
	return urd(rng);
}