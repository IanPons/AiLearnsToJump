#pragma once
#include "Network.h"

class Individual
{
public:
    Individual(int num_layers, int layer_size, int input_size, int output_size)
    {
        for(int i = 0; i < num_layers; i++)
        {
            nn.addLayer(layer_size, input_size);
            input_size = layer_size;
        }
        nn.addLayer(output_size, input_size);
        // nn.getDescription();
        dna = nn.getDNA();
    }

    std::vector<double> takeAction(std::vector<double> inputs)
    {
        return nn.FeedForward(inputs);
    }

    Network nn;
    std::vector<double> dna;
    double fitness;

};
