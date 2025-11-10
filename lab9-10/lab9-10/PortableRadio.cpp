#include "PortableRadio.h"
PortableRadio::PortableRadio(string n, double f, double p, int b)
    : Radiostation(n, f, p), batteryCapacity(b) {}
void PortableRadio::input() {
    Radiostation::input();
    cout << "Ємність батареї (мА·год): ";
    cin >> batteryCapacity;
}
void PortableRadio::show() const {
    cout << "[ПОРТАТИВНА РАЦІЯ] ";
    Radiostation::show();
    cout << "Ємність батареї: " << batteryCapacity << " мА·год" << endl;
    cout << "Радіус дії: " << range() << " км" << endl;
}
double PortableRadio::range() const {
    return (power * 0.3 + batteryCapacity / 2000.0);
}
