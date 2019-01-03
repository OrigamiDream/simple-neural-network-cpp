//
// Created by OrigamiDream on 2019-01-03.
//

#pragma once

#include "Global.h"
#include "Layer.h"
#include "Matrix.h"

typedef std::vector<Layer> vLayerList;
typedef std::vector<Matrix> vMatrixList;
typedef std::vector<Layer::Builder> vLayerBuilderList;

class Network {

private:
    vLayerList layers;
    vMatrixList oLayers;
    double learningRate;
    double iterations;

public:
    class Builder {

    private:
        vLayerBuilderList layers;
        double learningRate = 0.1;
        vNeuron input;
        Long iterations;

        Builder * addLayer(Layer::Builder builder);

        Builder * inputNeurons(vNeuron inputNeurons);

        Builder * setLearningRate(double learningRate);

        Builder * setIterations(Long iterations);

        Network build();
    };

    explicit Network(Builder * builder);

};