#include <iostream>
#include "Amplifier.h"
#include "AmplifierDouble.h"
#include "AmplifierPair.h"
using namespace std;
int main() {
    cout << "=== Тест програми ===" << endl;
    Amplifier<int> a1(150, 12, 2);
    a1.show();
    Amplifier<double> a2(47.5, 15, 3);
    a2.show();
    Amplifier<pair<int,int>> a3({100, 50}, 9, 1);
    a3.show();
    return 0;
}
