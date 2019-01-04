#include <iostream>
#include "Network.h"

void analyze(vMatrix test, Network network);

int main() {
    std::cout << "Starting neural network" << std::endl;
    Network * pNetwork = Network::builder()->setLearningRate(0.1)->setIterations(100000)->setInputNeurons(2)
            ->addLayer(Layer::builder()->setNeurons(4)->setFunctionType(FunctionTypes::SIGMOID))
            ->addLayer(Layer::builder()->setNeurons(3)->setFunctionType(FunctionTypes::SIGMOID))
            ->addLayer(Layer::builder()->setNeurons(1)->setFunctionType(FunctionTypes::SIGMOID))
            ->build();

    Network network = *pNetwork;

    vMatrix inputs {{ 0, 0 }, { 0, 1 }, { 1, 0 }, { 1, 1 }};
    vMatrix outputs {{ 0 }, { 1 }, { 1 }, { 0 }};

    network.train(inputs, outputs);

    analyze({{ 1, 1 }}, network);
    analyze({{ 1, 0 }}, network);
    analyze({{ 0, 1 }}, network);
    analyze({{ 0, 0 }}, network);
}

void analyze(vMatrix test, Network network) {
    network.think(std::move(test));

    vRow array = network.getOutput().getMatrix()[0];
    int result[array.size()];
    for(Long i = 0; i < array.size(); i++) {
        double value = array[i];
        if(value >= 0.5) {
            result[i] = 1;
        } else {
            result[i] = 0;
        }
    }

    std::cout << result << std::endl;
}