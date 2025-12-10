#pragma once
#include <iostream>
#include <utility>
using namespace std;
template <typename T, typename U>
class Amplifier<pair<T, U>> {
private:
    pair<T, U> gain;
    double voltage;
    int inputs;
public:
    Amplifier(pair<T, U> g, double v, int in)
        : gain(g), voltage(v), inputs(in) {}
    void show() {
        cout << "Операційний підсилювач [часткова спеціалізація pair<T,U>]:" << endl;
        cout << "  Підсилення: " << gain.first << " / " << gain.second << endl;
        cout << "  Напруга живлення: " << voltage << " В" << endl;
        cout << "  Входів: " << inputs << endl << endl;
    }
};
