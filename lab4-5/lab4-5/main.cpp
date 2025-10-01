#include <iostream>
#include <string>
using namespace std;

class OpAmp {
private:
    double gain;
    double voltage;
    int inputs;

public:
    OpAmp() {
        gain = 1.0;
        voltage = 5.0;
        inputs = 2;
        cout << "Створено OpAmp за замовчуванням\n";
    }

    OpAmp(double g, double v, int in) {
        setGain(g);
        setVoltage(v);
        setInputs(in);
        cout << "Створено OpAmp з параметрами\n";
    }
    ~OpAmp() {
        cout << "Об'єкт OpAmp знищено\n";
    }
    void setGain(double g) {
        if (g > 0) gain = g;
        else {
            gain = 1.0;
            cout << "Некоректний коеф. підсилення, встановлено 1.0\n";
        }
    }

    void setVoltage(double v) {
        if (v > 0) voltage = v;
        else {
            voltage = 5.0;
            cout << "Некоректна напруга, встановлено 5.0\n";
        }
    }

    void setInputs(int in) {
        if (in > 0) inputs = in;
        else {
            inputs = 2;
            cout << "Некоректна кількість входів, встановлено 2\n";
        }
    }

    void printInfo() {
        cout << "=== OpAmp Info ===\n";
        cout << "Коефіцієнт підсилення: " << gain << endl;
        cout << "Напруга живлення: " << voltage << " В\n";
        cout << "Кількість входів: " << inputs << endl;
    }
};

int main() {
    OpAmp op1;
    op1.printInfo();

    cout << endl;

    OpAmp op2(100, 12, 3);
    op2.printInfo();
    cout << endl;
    op1.setGain(-50);
    op1.setVoltage(15);
    op1.setInputs(4);
    op1.printInfo();

    return 0;
}
