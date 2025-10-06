#pragma once
#include <array>
#include <iostream>

const int SIZE = 3;

struct OpAmp {
    double gain;
    double voltage;
    int inputs;
};

class OpAmpArray {
private:
    std::array<OpAmp, SIZE> opamps;

public:
    OpAmpArray();

    ~OpAmpArray();

    void inputData();

    void outputData() const;

    bool validate(const OpAmp &amp) const;
};
