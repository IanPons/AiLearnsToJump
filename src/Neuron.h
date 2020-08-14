#pragma once
#include "random_num.h"
#include <iostream>
#include <vector>
#include <ctime>

class Neuron
{	
public:
	Neuron(int input_size)
	{
		static std::mt19937 rng(time(NULL)); 

		for(int i = 0; i < input_size; i++)
		{
			weights.push_back(generateRandomDouble(rng, -1, 1));		
		}
	}

	std::vector<double> getWeights()
	{
		return this->weights;
	}

	double dotProduct(std::vector<double> i1, std::vector<double> i2)
	{
		double sum = 0;

		if(i1.size() == i2.size())
		{
			for(int i = 0; i < i1.size(); i++)
			{
				sum += i1[i] * i2[i];
			}
		}
		else std::cout << "WARNING, INPUT AND WEIGHTS DON'T HAVE THE SAME SIZE." << std::endl;
		return sum;

	}


private:
	std::vector<double> weights;

};

