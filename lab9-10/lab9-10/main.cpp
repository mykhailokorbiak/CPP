#include <iostream>
#include <vector>
#include <memory>
#include "BaseStation.h"
#include "PortableRadio.h"
using namespace std;
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
    double totalRange = 0;
    for (auto &st : stations) totalRange += st->range();
    double averageRange = totalRange / stations.size();
    cout << "\n--- Інформація про всі пристрої ---\n";
    for (auto &st : stations) {
        st->show();
        cout << "-----------------------------------\n";
    }
    cout << "Середній радіус дії: " << averageRange << " км" << endl;
}
