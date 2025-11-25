#include "HandheldRadio.h"
HandheldRadio::HandheldRadio()
    : RadioStation(), batteryCapacityAh(2.0), weightKg(0.3), hasDisplay(true) {}
HandheldRadio::HandheldRadio(const std::string& n, const std::string& loc,
                             double minF, double maxF, double power,
                             double capacity, double weight, bool display)
    : RadioStation(n, loc, minF, maxF, power),
      batteryCapacityAh(capacity), weightKg(weight), hasDisplay(display)
{
    if (batteryCapacityAh <= 0 || weightKg <= 0)
        throw RadioException("Невірні параметри портативної рації");
}
void HandheldRadio::input() {
    std::cout << "\n--- Ввід даних для портативної рації ---\n";
    RadioStation::input();
    std::cout << "Ємність акумулятора (Ah): ";
    if (!(std::cin >> batteryCapacityAh))
        throw RadioException("Помилка вводу ємності акумулятора");
    if (batteryCapacityAh <= 0)
        throw RadioException("Ємність повинна бути > 0");
    std::cout << "Вага (кг): ";
    if (!(std::cin >> weightKg))
        throw RadioException("Помилка вводу ваги");
    if (weightKg <= 0)
        throw RadioException("Вага повинна бути > 0");
    int d;
    std::cout << "Наявність дисплея (1 - так, 0 - ні): ";
    if (!(std::cin >> d))
        throw RadioException("Помилка вводу прапорця дисплея");
    if (d != 0 && d != 1)
        throw RadioException("Прапорець дисплея повинен бути 0 або 1");
    hasDisplay = (d == 1);
}
void HandheldRadio::print(std::ostream& os) const {
    RadioStation::print(os);
    os << "Ємність акумулятора: " << batteryCapacityAh << " Ah\n";
    os << "Вага: " << weightKg << " кг\n";
    os << "Дисплей: " << (hasDisplay ? "так" : "ні") << "\n";
}
void HandheldRadio::save(std::ostream& os) const {
    RadioStation::save(os);
    os << batteryCapacityAh << ' ' << weightKg << ' ' << hasDisplay << '\n';
}
void HandheldRadio::load(std::istream& is) {
    RadioStation::load(is);
    int d;
    if (!(is >> batteryCapacityAh >> weightKg >> d))
        throw RadioException("Помилка читання полів рації з файлу");
    hasDisplay = (d != 0);
    if (batteryCapacityAh <= 0 || weightKg <= 0)
        throw RadioException("Невірні параметри рації (файл)");
}
