#include "opamp.h"

int main() {
    OpAmpArray arr;

    arr.inputData();
    arr.outputData();
    
    OpAmp extra = {10, 12, 2};
    arr.addOpAmp(extra);
    arr.outputData();

    arr.removeLast();
    arr.outputData();

    arr.clearAll();
    arr.outputData();

    return 0;
}
