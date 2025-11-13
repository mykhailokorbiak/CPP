#include "Radiostation.h"

Radiostation::Radiostation(string n, double f, double p)
    : name(n), frequency(f), power(p) {}

void Radiostation::input() {
    cout << "Назва: ";
    cin.ignore();
    getline(cin, name);
    cout << "Частота (МГц): ";
    cin >> frequency;
    cout << "Потужність (Вт): ";
    cin >> power;
}

void Radiostation::show() const {
    cout << "Назва: " << name
         << " | Частота: " << frequency << " МГц"
         << " | Потужність: " << power << " Вт";
}
