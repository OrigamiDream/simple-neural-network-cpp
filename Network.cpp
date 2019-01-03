//
// Created by OrigamiDream on 2019-01-03.
//
#include "Network.h"

Network::Builder *Network::Builder::addLayer(Layer::Builder builder) {
    return nullptr;
}

Network::Builder *Network::Builder::inputNeurons(vNeuron inputNeurons) {
    return nullptr;
}

Network::Builder *Network::Builder::setLearningRate(double learningRate) {
    return nullptr;
}

Network::Builder *Network::Builder::setIterations(Long iterations) {
    return nullptr;
}

Network Network::Builder::build() {
    return Network(this);
}

Network::Network(Network::Builder *builder) {

}
