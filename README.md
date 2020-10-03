![alt text](https://github.com/IanPons/AiLearnsToJump/blob/master/assets/jumping.gif)

# AiLearnsToJump
Neural Network and Genetic Algorithm implementation for a simple jumping game made using the SFML library.

# Resources: 
The whole project is written in C++. <br>
Genetic algorithm: The *nature of code* book by Daniel Shiffman (https://natureofcode.com) specifically chapter 9.<br> 
GeeksForGeeks article (https://www.geeksforgeeks.org/genetic-algorithms/).

Neural Networks: 3Blue1Brown playlist about NeuralNets (https://www.youtube.com/watch?v=aircAruvnKk&list=PLZHQObOWTQDNU6R1_67000Dx_ZCJB-3pi).<br>
*Towards Data Science* article by David Fumo (https://towardsdatascience.com/a-gentle-introduction-to-neural-networks-series-part-1-2b90b87795bc).

# How it works:
Each individual has a neural networks that consists of 2 inputs (Distace from the player to the obstacle, and the obstacle velocity) 1 hidden layer with 2 neurons and 1 output neuron. The activation function used in all neurons was the *ReLu* function. <br>
For each generation one individual is selected (best fitness) and mutated to create another generation. <br>
Population size: 5 <br>
Mutation rate: 5%
