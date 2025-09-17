#include "opamp.h"

// Конструктор
OpAmpArray::OpAmpArray() {
    std::cout << "Створено масив операційних підсилювачів (" << SIZE << " шт.)\n";
}

// Деструктор
OpAmpArray::~OpAmpArray() {
    std::cout << "Знищення масиву операційних підсилювачів\n";
}

// Перевірка правильності даних
bool OpAmpArray::validate(const OpAmp &amp) const {
    if (amp.gain <= 0) return false;
    if (amp.voltage <= 0 || amp.voltage > 50) return false;
    if (amp.inputs <= 0 || amp.inputs > 10) return false;  
    return true;
}

// Введення даних
void OpAmpArray::inputData() {
    for (int i = 0; i < SIZE; i++) {
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
            i--; // повторити для цього елемента
        } else {
            opamps[i] = amp;
        }
    }
}

// Виведення даних
void OpAmpArray::outputData() const {
    std::cout << "\nСписок операційних підсилювачів:\n";
    for (int i = 0; i < SIZE; i++) {
        std::cout << "Підсилювач #" << i + 1 << ":\n";
        std::cout << "  Коефіцієнт підсилення: " << opamps[i].gain << "\n";
        std::cout << "  Напруга живлення: " << opamps[i].voltage << " В\n";
        std::cout << "  Кількість входів: " << opamps[i].inputs << "\n";
    }
}
