#include "opamp.h"

OpAmpArray::OpAmpArray() {
    std::cout << "Створено динамічний масив операційних підсилювачів\n";
}

OpAmpArray::~OpAmpArray() {
    std::cout << "Знищення масиву операційних підсилювачів\n";
}

bool OpAmpArray::validate(const OpAmp &amp) const {
    if (amp.gain <= 0) return false;
    if (amp.voltage <= 0 || amp.voltage > 50) return false;
    if (amp.inputs <= 0 || amp.inputs > 10) return false;
    return true;
}

void OpAmpArray::inputData() {
    int n;
    std::cout << "Скільки підсилювачів хочете ввести? ";
    std::cin >> n;

    for (int i = 0; i < n; i++) {
        OpAmp amp;
        std::cout << "\nВведіть дані для підсилювача #" << i + 1 << ":\n";

        std::cout << "Коефіцієнт підсилення: ";
        std::cin >> amp.gain;

        std::cout << "Напруга живлення (В): ";
        std::cin >> amp.voltage;

        std::cout << "Кількість входів: ";
        std::cin >> amp.inputs;

        if (!validate(amp)) {
            std::cout << "❌ Помилка: некоректні дані. Повторіть введення.\n";
            i--;
        } else {
            opamps.push_back(amp);
        }
    }
}

void OpAmpArray::outputData() const {
    std::cout << "\nСписок операційних підсилювачів:\n";
    for (size_t i = 0; i < opamps.size(); i++) {
        std::cout << "Підсилювач #" << i + 1 << ":\n";
        std::cout << "  Коефіцієнт підсилення: " << opamps[i].gain << "\n";
        std::cout << "  Напруга живлення: " << opamps[i].voltage << " В\n";
        std::cout << "  Кількість входів: " << opamps[i].inputs << "\n";
    }
}

void OpAmpArray::addOpAmp(const OpAmp &amp) {
    if (validate(amp)) {
        opamps.push_back(amp);
    } else {
        std::cout << "❌ Неможливо додати: некоректні дані\n";
    }
}

void OpAmpArray::removeLast() {
    if (!opamps.empty()) {
        opamps.pop_back();
        std::cout << "✅ Останній підсилювач видалено\n";
    } else {
        std::cout << "❌ Масив порожній\n";
    }
}

void OpAmpArray::clearAll() {
    opamps.clear();
    std::cout << "✅ Масив очищено\n";
}
