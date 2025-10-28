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
    void addOpAmp(const OpAmp &amp);      // додати в кінець
    void insertAt(const OpAmp &amp, int index); // вставити у довільне місце
    void removeAt(int index);           // видалити за індексом
    void removeLast();                  // видалити останній
    void clearAll();                    // очистити весь вектор
    void swapElements(int i, int j);    // обмін двох елементів місцями
};
