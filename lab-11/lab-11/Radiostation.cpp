#include "Radiostation.h"

Radiostation::Radiostation(string n, double f, double p)
    : name(n), frequency(f), power(p) {}

void Radiostation::input() {
    cin.ignore();
    cout << "Назва: ";
    getline(cin, name);

    cout << "Частота (МГц): ";
    cin >> frequency;

    cout << "Потужність (Вт): ";
    cin >> power;
}

void Radiostation::show() const {
    cout << name << " | " << frequency << " МГц | " << power << " Вт";
}
