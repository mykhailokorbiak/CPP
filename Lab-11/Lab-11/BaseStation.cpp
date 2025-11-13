#include "BaseStation.h"

BaseStation::BaseStation(string n, double f, double p, double h)
    : Radiostation(n, f, p), antennaHeight(h) {}

void BaseStation::input() {
    Radiostation::input();
    cout << "Висота антени (м): ";
    cin >> antennaHeight;
}

void BaseStation::show() const {
    cout << "[Базова станція] ";
    Radiostation::show();
    cout << " | Висота антени: " << antennaHeight
         << " м | Радіус дії: " << range() << " км\n";
}

double BaseStation::range() const {
    return (power * 0.4 + antennaHeight * 0.3);
}
