#include <iostream>
using namespace std;

class OperationalAmplifier {
private:
    double gain;      // коеф. підсилення
    double voltage;   // напруга живлення
    int inputs;       // кількість входів
public:
    // конструктор за замовчуванням
    OperationalAmplifier() : gain(1.0), voltage(5.0), inputs(2) {}

    // конструктор з параметрами
    OperationalAmplifier(double g, double v, int in)
        : gain(g), voltage(v), inputs(in) {}

    // деструктор
    ~OperationalAmplifier() {}

    // методи з параметрами-посиланнями
    void setGain(const double& g) { gain = g; }
    void setVoltage(const double& v) { voltage = v; }
    void setInputs(const int& in) { inputs = in; }

    // гетер для gain
    double getGain() const { return gain; }

    // вивід інформації
    void display() const {
        cout << "Операційний підсилювач:\n";
        cout << "  Коеф. підсилення: " << gain << endl;
        cout << "  Напруга живлення: " << voltage << " В\n";
        cout << "  Кількість входів : " << inputs << endl;
    }
};

// функція, що змінює підсилення через посилання на об’єкт
void increaseGain(OperationalAmplifier& op, const double& add) {
    double newGain = op.getGain() + add; // беремо значення через гетер
    op.setGain(newGain);
}

int main() {
    OperationalAmplifier op1;                 // за замовчуванням
    OperationalAmplifier op2(100.0, 12.0, 2); // з параметрами

    cout << "[До змін]\n";
    op1.display();
    op2.display();

    double newGain = 150;
    op2.setGain(newGain);

    double newV = 15;
    op2.setVoltage(newV);

    int newInputs = 3;
    op2.setInputs(newInputs);

    // додаткова функція
    increaseGain(op2, 20);

    cout << "\n[Після змін]\n";
    op2.display();

    return 0;
}
