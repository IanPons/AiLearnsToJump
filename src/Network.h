#pragma once
#include "Layer.h"

class Network
{
public:
	Network() {}

	void addLayer(int layer_size, int input_size)
	{
		Layer layer(layer_size, input_size);
		Layers.push_back(layer);
	
	}

	std::vector<Layer> getLayers() { return this->Layers; }

	void getDescription()
	{
		std::cout << "Number of layers: " << this->Layers.size()  << std::endl;
		for(int layer = 0; layer < this->Layers.size(); layer++)
		{
			std::cout << "Layer: " << layer << std::endl;
			std::vector<Neuron> neuronios = this->Layers[layer].getNeurons();
			std::cout << "Neurons in this layer: " << neuronios.size() << std::endl;
			for(int neuronio = 0; neuronio < neuronios.size(); neuronio++)
			{
				std::vector<double> pesos = neuronios[neuronio].getWeights();
				for(int p = 0; p < pesos.size(); p++)
				{
					std::cout << pesos[p] << std::endl;
				}
			}
			std::cout << std::endl;
		}
	}

	std::vector<double> FeedForward(std::vector<double> inputs)
	{
		for(int i = 0; i < Layers.size(); i++)
		{
			inputs = Layers[i].FeedForwardL(inputs);
		}

		return inputs;
	}

	std::vector<double> getDNA()
	{
		std::vector<double> DNA;
		for(int layer = 0; layer < Layers.size(); layer++)
		{
			std::vector<Neuron> neurons = Layers[layer].getNeurons();
			for(int neuron = 0; neuron < neurons.size(); neuron++)
			{
				std::vector<double> ws = neurons[neuron].getWeights();
				for(int i = 0; i < ws.size(); i++)
				{
					DNA.push_back(ws[i]);
				}
			}
		}
		return DNA;
	}

private:
	std::vector<Layer> Layers;
};
