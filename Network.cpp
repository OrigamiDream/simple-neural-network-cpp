//
// Created by OrigamiDream on 2019-01-03.
//
#include "Network.h"

Network::Builder * Network::Builder::addLayer(Layer::Builder * builder) {
    this->bLayers.push_back(*builder);
    return this;
}

Network::Builder * Network::Builder::setInputNeurons(vNeuron inputNeurons) {
    this->bInput = inputNeurons;
    return this;
}

Network::Builder * Network::Builder::setLearningRate(double learningRate) {
    this->bLearningRate = learningRate;
    return this;
}

Network::Builder * Network::Builder::setIterations(Long iterations) {
    this->bIterations = iterations;
    return this;
}

Network * Network::Builder::build() {
    return new Network(this);
}

Network::Network(Network::Builder * pbuilder) {
    auto builder = *pbuilder;
    this->vLearningRate = builder.bLearningRate;
    this->vIterations = builder.bIterations;

    Long len = builder.bLayers.size();
    this->vLayers = vLayerList(len);
    this->oLayers = vMatrixList(len);
    Layer prev { FunctionTypes::SIGMOID, 0, 0 }; // default
    for(Long i = 0; i < len; i++) {
        Layer::Builder layer = builder.bLayers[i];
        if(i == 0) {
            this->vLayers[i] = *(new Layer(layer.bFunctionType, layer.bNeurons, builder.bInput));
        } else {
            this->vLayers[i] = *(new Layer(layer.bFunctionType, (i == len - 1) ? layer.bNeurons - 1 : layer.bNeurons, prev.vNeurons));
        }
        prev = std::move(this->vLayers[i]);
    }
}

Network::Builder *Network::builder() {
    return new Network::Builder();
}

void Network::think(vMatrix input) {
    think(*(new Matrix(std::move(input))));
}

void Network::think(Matrix input) {
    for(Long i = 0; i < vLayers.size(); i++) {
        Layer layer = vLayers[i];

        if(i == 0) {
            oLayers[i] = (input * layer.vWeights).apply(layer.vFunctionType.getFunction());
        } else {
            oLayers[i] = (oLayers[i - 1] * layer.vWeights).apply(layer.vFunctionType.getFunction());
        }
    }
}

void Network::train(vMatrix input, vMatrix output) {
    train(Matrix(std::move(input)), Matrix(std::move(output)));
}

void Network::train(Matrix input, vMatrix output) {
    train(input, Matrix(std::move(output)));
}

void Network::train(vMatrix input, Matrix output) {
    train(Matrix(std::move(input)), output);
}

void Network::train(Matrix input, Matrix output) {
    for(Long iteration = 0; iteration < vIterations; iteration++) {
        think(input);

        Matrix prev;
        Matrix deltas[oLayers.size()];
        for(Long i = oLayers.size() - 1; i >= 0; i--) {
            Matrix layer = oLayers[i];
            Matrix delta;
            if(i == oLayers.size() - 1) {
                delta = (output - layer).scalar(layer.apply(vLayers[i].vFunctionType.getDerivative()));
            } else {
                delta = (prev * vLayers[i + 1].vWeights.transpose()).scalar(layer.apply(vLayers[i].vFunctionType.getDerivative()));
            }
            deltas[i] = delta;
            prev = delta;
        }

        for(Long i = 0; i < (sizeof(deltas) / sizeof(*deltas)); i++) {
            Matrix adjustment;
            if(i == 0) {
                adjustment = input.transpose() * deltas[i];
            } else {
                adjustment = oLayers[i - 1].transpose() * deltas[i];
            }
            adjustment = adjustment.apply([&](double x) {
                return vLearningRate * x;
            });

            vLayers[i].adjust(adjustment);

            delete &adjustment;
        }

        delete &prev;
        delete[] &deltas;
    }
}

Matrix Network::getOutput() {
    return oLayers[oLayers.size() - 1];
}
