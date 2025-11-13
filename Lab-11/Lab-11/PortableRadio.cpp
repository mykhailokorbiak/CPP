#include "PortableRadio.h"

PortableRadio::PortableRadio(string n, double f, double p, int b)
    : Radiostation(n, f, p), batteryCapacity(b) {}

void PortableRadio::input() {
    Radiostation::input();
    cout << "Ємність батареї (мА·год): ";
    cin >> batteryCapacity;
}

void PortableRadio::show() const {
    cout << "[Портативна рація] ";
    Radiostation::show();
    cout << " | Ємність батареї: " << batteryCapacity
         << " мА·год | Радіус дії: " << range() << " км\n";
}

double PortableRadio::range() const {
    return (power * 0.25 + batteryCapacity / 1500.0);
}
