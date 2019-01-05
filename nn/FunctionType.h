#pragma once

#include "Global.h"
#include <math.h>

class FunctionType {

private:
    vFunction fn;
    vFunction derivative_fn;

public:
    explicit FunctionType(vFunction vFn, vFunction vDerivative);

    vFunction getFunction();

    vFunction getDerivative();
};

namespace FunctionTypes {

    const FunctionType SIGMOID = FunctionType([](double x) {
        return 1.0 / (1.0 + exp(-x));
    }, [](double x) {
        return x * (1.0 - x);
    });

    const FunctionType TANH = FunctionType([](double x) {
        return tanh(x);
    }, [](double x) {
        return 1.0 - tanh(x) * tanh(x);
    });

    const FunctionType RELU = FunctionType([](double x) {
        return (x > 0.0) ? x : 0.0;
    }, [](double x) {
        return (x < 0.0 ? 1.0 : 0.0);
    });

}