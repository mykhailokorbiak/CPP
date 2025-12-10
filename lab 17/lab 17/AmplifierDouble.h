#pragma once
#include <iostream>
using namespace std;
template <>
class Amplifier<double> {
private:
    double gain;
    double voltage;
    int inputs;
public:
    Amplifier(double g, double v, int in) : gain(g), voltage(v), inputs(in) {}
    void show() {
        cout << "Операційний підсилювач [повна спеціалізація double]:" << endl;
        cout << "  Підсилення: " << scientific << gain << endl;
        cout << "  Живлення: ±" << voltage << " В" << endl;
        cout << "  Входів: " << inputs << endl << endl;
    }
};
