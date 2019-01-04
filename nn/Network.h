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

public:
    vLayerList vLayers;
    vMatrixList oLayers;
    double vLearningRate;
    Long vIterations;

public:
    class Builder {

    public:
        Builder(): bLayers(vLayerBuilderList()), bInput(0), bIterations(0) {}

        Builder * addLayer(Layer::Builder * builder);

        Builder * setInputNeurons(vNeuron inputNeurons);

        Builder * setLearningRate(double learningRate);

        Builder * setIterations(Long iterations);

        Network * build();

    public:
        double bLearningRate = 0.1;
        Long bIterations;
        vLayerBuilderList bLayers;
        vNeuron bInput;
    };

public:
    static Builder * builder();

    explicit Network(Builder * pbuilder);

    void think(vMatrix * input);

    void think(Matrix * input);

    void train(vMatrix * input, vMatrix * output);

    void train(Matrix * input, vMatrix * output);

    void train(vMatrix * input, Matrix * output);

    void train(Matrix * input, Matrix * output);

    Matrix getOutput();

};