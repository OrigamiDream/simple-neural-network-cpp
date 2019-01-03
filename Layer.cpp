//
// Created by OrigamiDream on 2019-01-03.
//

#include "Layer.h"

Layer::Layer(FunctionType fnType, vNeuron neuronNum, vNeuron inputNum) : weights(*new Matrix(inputNum, neuronNum)), functionType(std::move(fnType)), neurons(neuronNum) {
    for(vNeuron i = 0; i < inputNum; i++) {
        for(vNeuron j = 0; j < neuronNum; j++) {
            if(i == inputNum - 1) {
                weights.set(i, j, 1);
            } else {
                weights.set(i, j, 0);
            }
        }
    }
}

void Layer::adjust(Matrix adjust) {
    weights = weights + std::move(adjust);
}

Layer::Builder * Layer::builder() {
    return new Layer::Builder();
}

Layer::Builder * Layer::Builder::function(FunctionType fnType) {
    functionType = std::move(fnType);
    return this;
}

Layer::Builder * Layer::Builder::neuron(int neurons) {
    this->neurons = neurons + 1;
    return this;
}