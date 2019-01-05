#pragma once

#include <iostream>
#include "Runnable.h"
#include "../nn/Network.h"

class LogicalGate: public Runnable {

public:
    void analyze(vMatrix test, Network network) {
        network.think(&test);

        vRow array = network.getOutput().getMatrix()[0];
        int result[array.size()];
        double actualResult[array.size()];
        for(Long i = 0; i < array.size(); i++) {
            double value = array[i];
            if(value >= 0.5) {
                result[i] = 1;
            } else {
                result[i] = 0;
            }
            actualResult[i] = value;
        }
        std::cout << "[" << test[0][0] << ", " << test[0][1] << "] -> " << result[0] << " (" << actualResult[0] << ")" << std::endl;
    }
};