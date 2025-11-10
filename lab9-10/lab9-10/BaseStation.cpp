#include "BaseStation.h"
BaseStation::BaseStation(string n, double f, double p, double h)
    : Radiostation(n, f, p), antennaHeight(h) {}
void BaseStation::input() {
    Radiostation::input();
    cout << "Висота антени (м): ";
    cin >> antennaHeight;
}
void BaseStation::show() const {
    cout << "[БАЗОВА СТАНЦІЯ] ";
    Radiostation::show();
    cout << "Висота антени: " << antennaHeight << " м" << endl;
    cout << "Радіус дії: " << range() << " км" << endl;
}
double BaseStation::range() const {
    return (power * 0.5 + antennaHeight * 0.3);
}
