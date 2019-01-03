//
// Created by OrigamiDream on 2019-01-03.
//

#pragma once

#include "Global.h"
#include "Matrix.h"
#include "FunctionType.h"

class Layer {

private:
    Matrix weights;
    FunctionType functionType;
    vNeuron neurons;

public:
    Layer(FunctionType fnType, vNeuron neuronNum, vNeuron inputNum);

    void adjust(Matrix adjust);

    class Builder {

    private:
        FunctionType functionType = SIGMOID;
        int neurons = 0;

    public:
        Builder * function(FunctionType fnType);

        Builder * neuron(int neurons);
    };

    static Builder * builder();
};