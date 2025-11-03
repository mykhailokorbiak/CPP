#include <iostream>
#include <string>
#include <vector>
#include <memory>
using namespace std;

class Radiostation {
protected:
    string name;
    double frequency;
    double power;

public:
    Radiostation(string n = "Unknown", double f = 100.0, double p = 10.0)
        : name(n), frequency(f), power(p) {}

    virtual ~Radiostation() {}

    virtual void input() {
        cout << "Назва радіостанції: ";
        cin >> name;
        cout << "Частота (МГц): ";
        cin >> frequency;
        cout << "Потужність (Вт): ";
        cin >> power;
    }

    virtual void show() const {
        cout << "Радіостанція: " << name
             << ", частота: " << frequency << " МГц, потужність: "
             << power << " Вт" << endl;
    }

    virtual double range() const = 0;
};

class BaseStation : public Radiostation {
    double antennaHeight; // м

public:
    BaseStation(string n = "Base", double f = 100.0, double p = 50.0, double h = 30.0)
        : Radiostation(n, f, p), antennaHeight(h) {}

    void input() override {
        Radiostation::input();
        cout << "Висота антени (м): ";
        cin >> antennaHeight;
    }

    void show() const override {
        cout << "[БАЗОВА СТАНЦІЯ] ";
        Radiostation::show();
        cout << "Висота антени: " << antennaHeight << " м" << endl;
        cout << "Радіус дії: " << range() << " км" << endl;
    }

    double range() const override {
        return (power * 0.5 + antennaHeight * 0.3);
    }
};

class PortableRadio : public Radiostation {
    int batteryCapacity;
public:
    PortableRadio(string n = "Portable", double f = 100.0, double p = 5.0, int b = 2000)
        : Radiostation(n, f, p), batteryCapacity(b) {}

    void input() override {
        Radiostation::input();
        cout << "Ємність батареї (мА·год): ";
        cin >> batteryCapacity;
    }

    void show() const override {
        cout << "[ПОРТАТИВНА РАЦІЯ] ";
        Radiostation::show();
        cout << "Ємність батареї: " << batteryCapacity << " мА·год" << endl;
        cout << "Радіус дії: " << range() << " км" << endl;
    }

    double range() const override {
        return (power * 0.3 + batteryCapacity / 2000.0);
    }
};

int main() {
    vector<shared_ptr<Radiostation>> stations;
    int n;
    cout << "Скільки пристроїв створити? ";
    cin >> n;

    for (int i = 0; i < n; ++i) {
        int type;
        cout << "\n1 — Базова станція, 2 — Портативна рація: ";
        cin >> type;

        if (type == 1)
            stations.push_back(make_shared<BaseStation>());
        else
            stations.push_back(make_shared<PortableRadio>());

        stations.back()->input();
    }

    cout << "\n--- Інформація про всі пристрої ---\n";
    for (auto &st : stations) {
        st->show();
        cout << "-----------------------------------\n";
    }

    return 0;
}
