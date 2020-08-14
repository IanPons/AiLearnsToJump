#include "Individual.h"

#define POPULATION_SIZE 5
#define MUTATION_RATE 0.05

#define NUM_LAYERS 2
#define INPUT_SIZE 2
#define OUTPUT_SIZE 1
#define LAYER_ZIZE 2

static std::mt19937 rnd(time(NULL)); // número aleatórios de verdade

void printVector(std::vector<double> &v)
{
    for(int i = 0; i < v.size(); i++)
    {
        std::cout << v[i] << ' ';
    }
    std::cout << '\n';
}

std::vector<Individual> createInitialPopulation()
{
    std::vector<Individual> initialPopulation;
    for(int i = 0; i < POPULATION_SIZE; i++)
    {
        Individual individual(NUM_LAYERS, LAYER_ZIZE, INPUT_SIZE, OUTPUT_SIZE);
        initialPopulation.push_back(individual);
    }
    return initialPopulation;
}

Individual reproduce(Individual &i1, Individual &i2)
{
    Individual child(NUM_LAYERS, LAYER_ZIZE, INPUT_SIZE, OUTPUT_SIZE);
    std::vector<double> childDna;
    std::vector<double> dna1 = i1.dna;
    std::vector<double> dna2 = i2.dna;
    for(int i = 0; i < dna1.size(); i++)
    {
        if (generateRandomDouble(rnd, 0, 1) >= 0.5f)
        {
            childDna.push_back(dna1[i]);
        }
        else childDna.push_back(dna2[i]);
    }
    child.dna = childDna;

    return child;
}

void mutate(Individual &individual)
{
    for(int i = 0; i < individual.dna.size(); i++)
    {
        double n = generateRandomDouble(rnd, 0, 1);
        if(n <= MUTATION_RATE)
        {
            individual.dna[i] = generateRandomDouble(rnd, -1, 1);
        }
    }
}

std::vector<Individual> generateNewPopulation(Individual &parent1)
{
    std::vector<Individual> newPopularion;
    for(int i = 0; i < POPULATION_SIZE; i++)
    {
        Individual child(NUM_LAYERS, LAYER_ZIZE, INPUT_SIZE, OUTPUT_SIZE);
        child.dna = parent1.dna;
        mutate(child);
        newPopularion.push_back(child);
    }

    return newPopularion;
}

void sortByScore(std::vector<Individual> &v)
{
  std::sort(v.begin(), v.end(), [](auto const& a, auto const& b) {
    return a.fitness > b.fitness;
  });
}



    // Teste da reprodução e mutação
    // Individual p1(2, 2, 2, 1);
    // Individual p2(2, 2, 2, 1);
    //
    // Individual p3 = reproduce(p1, p2);
    //
    // printVector(p1.dna);
    // printVector(p2.dna);
    //
    // printVector(p3.dna);
    //
    // mutate(p3);
    //
    // printVector(p3.dna);
