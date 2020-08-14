#include <SFML/Graphics.hpp>
#include <iostream>
#include "Player.h"
#include "Obstacle.h"
#include "Collision.h"
#include "neuroevolution.h"

using namespace sf;


int main()
{

    std::vector<Individual> population = createInitialPopulation();

    Color backgroudColor = Color::Cyan;
    RenderWindow window(VideoMode(900, 900), "Learning SFML", Style::Close);

    Clock clock;

    Player player;
    player.SetOrigin({ 0, player.getSize().y });
    player.SetPos({ 50, 800 });


    Obstacle obstacle;
    obstacle.SetOrigin({ 0, obstacle.GetSize().y });
    obstacle.SetPosition({850, 800});

    int generation = 0;
    int index = 0;

    printf("Generation: %i \n", generation);
    printf("Individual: %i \n", index);
    //Main Loop
    while (window.isOpen())
    {
        float deltaTime = clock.restart().asSeconds();

        // Event Loop
        Event evt;

        while (window.pollEvent(evt))
        {
            switch (evt.type)
            {
            case Event::Closed:
                window.close();
                break;

            }
        }

        window.clear(backgroudColor);

        double distance =  (obstacle.getXPos() - player.getPos().x) / 100;
        double obstacle_vel = obstacle.getVelocity() / 100;

        std::vector<double> output = population[index].takeAction( {distance, obstacle_vel });

        player.Movement(deltaTime, output);
        obstacle.Movement(deltaTime);

        player.UpdateTexture(deltaTime, 0.2f, 0);

        player.Draw(window);
        obstacle.Draw(window);

        if (CheckCollison(player, obstacle))
        {
            population[index].fitness = obstacle.score;
            index++;
            printf("Individual: %i\n", index);
            if (population[index].fitness >= 50)
            {
                printVector(population[index].dna);
            }
            if (index == POPULATION_SIZE)
            {
                sortByScore(population);
                std::cout << "Best score (this generation): " << population[0].fitness << '\n';
                Individual p1 = population[0];
                // std::cout << "Best of this generation: ";
                // printVector(p1.dna);
                // Individual p2 = population[1];
                population.clear();
                population = generateNewPopulation(p1);
                // std::cout << "Child example dna: ";
                // printVector(population[0].dna);
                index = 0;
                generation++;
                std::cout << "Generation: " << generation << std::endl;
            }
            obstacle.score = 0;

            obstacle.SetPosition({ 1000, 800 });
            obstacle.SetVelocity(400.0f);

        }

        window.display();
    }
}
