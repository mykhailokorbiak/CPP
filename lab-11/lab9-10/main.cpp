#include <vector>
#include <memory>
#include "BaseStation.h"
#include "PortableRadio.h"
#include "RadioAnalyzer.h"

int main() {
    vector<Radiostation*> stations;

    int n;
    cout << "Скільки пристроїв створити? ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        int type;
        do {
            cout << "\n1 — Базова   2 — Портативна : ";
            cin >> type;
            if (type != 1 && type != 2)
                cout << "Помилка! Введіть лише 1 або 2.\n";
        } while(type != 1 && type != 2);

        if (type == 1)
            stations.push_back(new BaseStation());
        else
            stations.push_back(new PortableRadio());

        stations.back()->input();
    }

    cout << "\n--- Дані ---\n";
    for (auto p : stations) {
        p->show();
        cout << endl;
    }

    cout << "\nСередня потужність: " << RadioAnalyzer::averagePower(stations) << " Вт\n";
    cout << "Максимальний радіус: " << RadioAnalyzer::maxRange(stations) << " км\n";

    for (auto p : stations) delete p;
}
