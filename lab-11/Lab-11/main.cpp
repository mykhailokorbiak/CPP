#include <iostream>
#include <vector>
#include <memory>
#include "BaseStation.h"
#include "PortableRadio.h"
#include "FriendAnalyzer.h"
using namespace std;

int main() {
    vector<shared_ptr<Radiostation>> stations;
    int n;
    cout << "Скільки пристроїв створити? ";
    cin >> n;

    for (int i = 0; i < n; ++i) {
        int type;
        while (true) {
            cout << "\n1 — Базова  2 — Портативна : ";
            cin >> type;
            if (type == 1 || type == 2)
                break;
            cout << "❌ Некоректний вибір! Введіть 1 або 2.\n";
        }

        shared_ptr<Radiostation> st;
        if (type == 1)
            st = make_shared<BaseStation>();
        else
            st = make_shared<PortableRadio>();

        st->input();
        stations.push_back(st);
    }

    cout << "\n--- Інформація про пристрої ---\n";
    for (auto &s : stations) s->show();

    cout << "\nСередня потужність: " << FriendAnalyzer::averagePower(stations) << " Вт";
    cout << "\nМаксимальний радіус дії: " << FriendAnalyzer::maxRange(stations) << " км\n";

    return 0;
}
