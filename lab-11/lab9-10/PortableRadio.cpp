#include "PortableRadio.h"

PortableRadio::PortableRadio(string n, double f, double p, int b)
    : Radiostation(n, f, p), batteryCapacity(b) {}

void PortableRadio::input() {
    Radiostation::input();
    cout << "Ємність батареї (мА·год): ";
    cin >> batteryCapacity;
}

void PortableRadio::show() const {
    cout << "[Портативна] ";
    Radiostation::show();
    cout << " | Батарея: " << batteryCapacity << " мА·год"
         << " | Радіус: " << range() << " км";
}

double PortableRadio::range() const {
    return (power * 0.3 + batteryCapacity / 2000.0);
}

