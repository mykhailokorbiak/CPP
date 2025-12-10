#pragma once
#include <iostream>
using namespace std;
template <typename T>
class Amplifier {
private:
    T gain;
    double voltage;
    int inputs;
public:
    Amplifier(T g, double v, int in) : gain(g), voltage(v), inputs(in) {}

    void show() {
        cout << "Операційний підсилювач (загальний шаблон):" << endl;
        cout << "  Підсилення: " << gain << endl;
        cout << "  Напруга живлення: " << voltage << endl;
        cout << "  Кількість входів: " << inputs << endl << endl;
    }
};
