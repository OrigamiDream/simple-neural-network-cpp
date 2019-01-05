#include "LogicalGate.h"

class AND: public LogicalGate {

public:
    void run() override {
        std::cout << "Starting AND" << std::endl;

        Network * pNetwork = Network::builder()->setLearningRate(0.1)->setIterations(10000)->setInputNeurons(2)
                ->addLayer(Layer::builder()->setNeurons(3)->setFunctionType(FunctionTypes::SIGMOID))
                ->addLayer(Layer::builder()->setNeurons(1)->setFunctionType(FunctionTypes::SIGMOID))
                ->build();

        Network network = *pNetwork;

        vMatrix inputs {{ 0, 0 }, { 0, 1 }, { 1, 0 }, { 1, 1 }};
        vMatrix outputs {{ 0 }, { 0 }, { 0 }, { 1 }};

        network.train(&inputs, &outputs);

        analyze({{ 1, 1 }}, network);
        analyze({{ 1, 0 }}, network);
        analyze({{ 0, 1 }}, network);
        analyze({{ 0, 0 }}, network);
    }

};