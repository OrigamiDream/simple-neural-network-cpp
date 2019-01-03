//
// Created by OrigamiDream on 2019-01-03.
//

#include "FunctionType.h"

FunctionType::FunctionType(vFunction vFn, vFunction vDerivative) {
    fn = std::move(vFn);
    derivative_fn = std::move(vDerivative);
}

vFunction FunctionType::getFunction() {
    return fn;
}

vFunction FunctionType::getDerivative() {
    return derivative_fn;
}