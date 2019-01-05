#include <iostream>
#include "nn/Network.h"
#include "runnable/Runnable.h"
#include "runnable/OR.h"
#include "runnable/AND.h"
#include "runnable/XOR.h"
#include "runnable/XAND.h"

int main() {
    Runnable * runnable = nullptr;
    runnable = new OR();
    // runnable = new AND();
    // runnable = new XOR();
    // runnable = new XAND();

    runnable->run();

    delete runnable;
}