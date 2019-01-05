#pragma once

#include "Global.h"
#include "Matrix.h"
#include "FunctionType.h"

class Layer {

public:
    Matrix vWeights;
    FunctionType vFunctionType;
    vNeuron vNeurons;

    explicit Layer(FunctionType fnType, vNeuron neuronNum, vNeuron inputNum);

    Layer(): vFunctionType(FunctionTypes::SIGMOID), vNeurons(0), vWeights(Matrix()) {}

    void adjust(Matrix adjust);

    class Builder {

    public:
        FunctionType bFunctionType;
        vNeuron bNeurons;

        Builder(): bFunctionType(FunctionTypes::SIGMOID), bNeurons(0) {}

        Builder * setFunctionType(FunctionType fnType);

        Builder * setNeurons(int neurons);
    };

    static Builder * builder();
};