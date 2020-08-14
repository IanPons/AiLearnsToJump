#pragma once
#include "Neuron.h"

class Layer
{
public:
	Layer(int layer_size, int input_size)
	{
		this->layer_size = layer_size;
		this->input_size = input_size;
		
		for(int i =0; i < layer_size; i++)
		{
			Neuron neuron(input_size);
			Neurons.push_back(neuron);	
		}
	}

	std::vector<Neuron> getNeurons()
	{
		return this->Neurons;
	}

	std::vector<double> FeedForwardL(std::vector<double> inputs)
	{
		std::vector<double> output;
		for(int neuron = 0; neuron < Neurons.size(); neuron++)
		{
			std::vector<double> weights = Neurons[neuron].getWeights();
			output.push_back(relu(Neurons[neuron].dotProduct(inputs, weights)));
		}

		return output;
	}

	double relu(double x)
	{
		if(x > 0) { return x; }
		return 0;
	}

private:
	std::vector<Neuron> Neurons;
	int layer_size;
	int input_size;
};
