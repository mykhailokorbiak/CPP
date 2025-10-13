#include <iostream>
#include <vector>
#include <string>
using namespace std;
class OpAmp {
    string name;
    double gain;
    double voltage;
    int inputs;
    bool railToRail;
public:
    OpAmp(string n = "OpAmp", double g = 1, double v = 5, int in = 2, bool rr = false)
        : name(n), gain(g), voltage(v), inputs(in), railToRail(rr) {
        validate();
    }
    void inputData() {
        cout << "\nВведіть назву підсилювача: ";
        getline(cin >> ws, name);
        cout << "Введіть коеф. підсилення, напругу, кількість входів і railToRail(0/1): ";
        cin >> gain >> voltage >> inputs >> railToRail;
        validate();
    }
    void printInfo() const {
        cout << name << " | Gain=" << gain
             << " | Voltage=" << voltage << "В"
             << " | Inputs=" << inputs
             << " | RailToRail=" << (railToRail ? "так" : "ні") << endl;
    }
    double getGain() const { return gain; }
    int getInputs() const { return inputs; }
    bool isRailToRail() const { return railToRail; }
private:
    void validate() {
        if (gain <= 0)  { cout << "[Увага] Некоректний gain → 1.0\n"; gain = 1; }
        if (voltage <= 0) { cout << "[Увага] Некоректна напруга → 5.0\n"; voltage = 5; }
        if (inputs <= 0) { cout << "[Увага] Некоректна кількість входів → 2\n"; inputs = 2; }
    }
};
int main() {
    OpAmp a("A1", 10, 9, 2, true);
    OpAmp b("B1", 100, 12, 3, false);
    OpAmp c("C1", -5, 0, -1, true);
    OpAmp user;
    cout << "\n--- Ввід користувача ---\n";
    user.inputData();
    vector<OpAmp> amps = {a, b, c, user};
    cout << "\n--- Всі підсилювачі ---\n";
    for (auto& x : amps) x.printInfo();
    double minGain; int minInputs; bool needRR;
    cout << "\nВведіть мінімальний gain, мінімальні inputs, railToRail(0/1): ";
    cin >> minGain >> minInputs >> needRR;
    cout << "\n=== Результати ===\n";
    bool found = false;
    for (auto& x : amps)
        if (x.getGain() >= minGain && x.getInputs() >= minInputs && x.isRailToRail() == needRR)
            { x.printInfo(); found = true; }
    if (!found)
        cout << "Немає підсилювачів, що відповідають критерію.\n";
    return 0;
}

