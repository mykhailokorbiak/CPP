#pragma once
#include <vector>
#include <iostream>

struct OpAmp {
    double gain;
    double voltage;
    int inputs;
};

class OpAmpArray {
private:
    std::vector<OpAmp> opamps;

public:
    OpAmpArray();
    ~OpAmpArray();

    void inputData();
    void outputData() const;
    bool validate(const OpAmp &amp) const;

    void addOpAmp(const OpAmp &amp);
    void removeLast();
    void clearAll();                
};
