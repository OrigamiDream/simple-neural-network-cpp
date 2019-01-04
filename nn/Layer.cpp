//
// Created by OrigamiDream on 2019-01-03.
//

#include "Layer.h"

Layer::Layer(FunctionType fnType, vNeuron neuronNum, vNeuron inputNum) : vWeights(Matrix(inputNum, neuronNum)), vFunctionType(std::move(fnType)), vNeurons(neuronNum) {
    for(vNeuron i = 0; i < inputNum; i++) {
        for(vNeuron j = 0; j < neuronNum; j++) {
            if(i == inputNum - 1) {
                vWeights.set(i, j, 1);
            } else {
                vWeights.set(i, j, 0);
            }
        }
    }
}

void Layer::adjust(Matrix adjust) {
    vWeights = vWeights + std::move(adjust);
}

Layer::Builder * Layer::builder() {
    return new Layer::Builder();
}

Layer::Builder * Layer::Builder::setFunctionType(FunctionType fnType) {
    bFunctionType = std::move(fnType);
    return this;
}

Layer::Builder * Layer::Builder::setNeurons(int neurons) {
    this->bNeurons = neurons + 1;
    return this;
}