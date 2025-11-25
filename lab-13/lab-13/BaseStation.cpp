#include "BaseStation.h"
BaseStation::BaseStation()
    : RadioStation(), maxClients(10), antennaHeight(20.0) {}
BaseStation::BaseStation(const std::string& n, const std::string& loc,
                         double minF, double maxF, double power,
                         int clients, double height)
    : RadioStation(n, loc, minF, maxF, power),
      maxClients(clients), antennaHeight(height)
{
    if (maxClients <= 0)
        throw RadioException("Кількість клієнтів базової станції повинна бути > 0");
    if (antennaHeight <= 0)
        throw RadioException("Висота антени повинна бути > 0");
}
void BaseStation::input() {
    std::cout << "\n--- Ввід даних для базової станції ---\n";
    RadioStation::input();
    std::cout << "Максимальна кількість клієнтів: ";
    if (!(std::cin >> maxClients))
        throw RadioException("Помилка вводу кількості клієнтів");
    if (maxClients <= 0)
        throw RadioException("Кількість клієнтів повинна бути > 0");
    std::cout << "Висота антени (м): ";
    if (!(std::cin >> antennaHeight))
        throw RadioException("Помилка вводу висоти антени");
    if (antennaHeight <= 0)
        throw RadioException("Висота антени повинна бути > 0");
}
void BaseStation::print(std::ostream& os) const {
    RadioStation::print(os);
    os << "Макс. клієнтів: " << maxClients << '\n';
    os << "Висота антени: " << antennaHeight << " м\n";
}
void BaseStation::save(std::ostream& os) const {
    RadioStation::save(os);
    os << maxClients << ' ' << antennaHeight << '\n';
}
void BaseStation::load(std::istream& is) {
    RadioStation::load(is);
    if (!(is >> maxClients >> antennaHeight))
        throw RadioException("Помилка читання полів базової станції з файлу");
    if (maxClients <= 0 || antennaHeight <= 0)
        throw RadioException("Невірні параметри базової станції (файл)");
}
