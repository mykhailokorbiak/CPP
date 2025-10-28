#include "opamp.h"

int main() {
    OpAmpArray arr;
    arr.inputData();
    arr.outputData();
    OpAmp newAmp = {20, 15, 2};
    arr.insertAt(newAmp, 1);
    arr.swapElements(0, 1);
    arr.removeAt(0);
    arr.outputData();
    return 0;
}
