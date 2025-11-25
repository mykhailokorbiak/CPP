#include "RadioStation.h"
#include <limits>
RadioStation::RadioStation()
    : name("noname"), location("unknown"),
      minFreqMHz(100.0), maxFreqMHz(200.0), powerW(10.0) {}
RadioStation::RadioStation(const std::string& n, const std::string& loc,
                           double minF, double maxF, double power)
    : name(n), location(loc), minFreqMHz(minF), maxFreqMHz(maxF), powerW(power)
{
    if (minFreqMHz <= 0 || maxFreqMHz <= 0 || minFreqMHz >= maxFreqMHz)
        throw RadioException("Невірний діапазон частот у конструкторі RadioStation");
    if (powerW <= 0)
        throw RadioException("Потужність повинна бути > 0 у конструкторі RadioStation");
}
RadioStation::~RadioStation() = default;
void RadioStation::inputChannels() {
    std::cout << "Кількість каналів: ";
    int count;
    if (!(std::cin >> count))
        throw RadioException("Помилка вводу (кількість каналів)");
    if (count < 0)
        throw RadioException("Кількість каналів не може бути від'ємною");
    channels.clear();
    for (int i = 0; i < count; ++i) {
        Channel ch{};
        std::cout << "\nКанал #" << (i + 1) << " (id, частота_MHz, опис_без_пробілів): ";
        if (!(std::cin >> ch.id >> ch.freqMHz >> ch.description))
            throw RadioException("Помилка вводу даних каналу");
        if (ch.freqMHz < minFreqMHz || ch.freqMHz > maxFreqMHz)
            throw RadioException("Частота каналу виходить за межі діапазону станції");
        channels.push_back(ch);
    }
}
void RadioStation::printChannels(std::ostream& os) const {
    os << "Канали (" << channels.size() << "):\n";
    for (const auto& ch : channels) {
        os << "   id=" << ch.id
           << " freq=" << ch.freqMHz << " MHz"
           << " desc=" << ch.description << '\n';
    }
}
void RadioStation::saveChannels(std::ostream& os) const {
    os << channels.size() << '\n';
    for (const auto& ch : channels) {
        os << ch.id << ' ' << ch.freqMHz << ' ' << ch.description << '\n';
    }
}
void RadioStation::loadChannels(std::istream& is) {
    int count;
    if (!(is >> count))
        throw RadioException("Помилка читання кількості каналів з файлу");
    if (count < 0)
        throw RadioException("Невірна кількість каналів у файлі");
    channels.clear();
    for (int i = 0; i < count; ++i) {
        Channel ch{};
        if (!(is >> ch.id >> ch.freqMHz >> ch.description))
            throw RadioException("Помилка читання даних каналу з файлу");
        channels.push_back(ch);
    }
}
void RadioStation::input() {
    std::cout << "Назва станції (без пробілів): ";
    std::cin >> name;
    std::cout << "Локація (без пробілів): ";
    std::cin >> location;
    std::cout << "Мінімальна частота (MHz): ";
    if (!(std::cin >> minFreqMHz))
        throw RadioException("Помилка вводу мінімальної частоти");
    std::cout << "Максимальна частота (MHz): ";
    if (!(std::cin >> maxFreqMHz))
        throw RadioException("Помилка вводу максимальної частоти");
    if (minFreqMHz <= 0 || maxFreqMHz <= 0 || minFreqMHz >= maxFreqMHz)
        throw RadioException("Невірний діапазон частот");
    std::cout << "Потужність (Вт): ";
    if (!(std::cin >> powerW))
        throw RadioException("Помилка вводу потужності");
    if (powerW <= 0)
        throw RadioException("Потужність повинна бути > 0");
    inputChannels();
}
void RadioStation::print(std::ostream& os) const {
    os << "Тип: " << type() << '\n';
    os << "Назва: " << name << "\nЛокація: " << location << '\n';
    os << "Діапазон: " << minFreqMHz << " - " << maxFreqMHz << " MHz\n";
    os << "Потужність: " << powerW << " W\n";
    printChannels(os);
}
void RadioStation::save(std::ostream& os) const {
    os << name << ' ' << location << ' '
       << minFreqMHz << ' ' << maxFreqMHz << ' ' << powerW << '\n';
    saveChannels(os);
}
void RadioStation::load(std::istream& is) {
    if (!(is >> name >> location >> minFreqMHz >> maxFreqMHz >> powerW))
        throw RadioException("Помилка читання полів базової станції з файлу");
    if (minFreqMHz <= 0 || maxFreqMHz <= 0 || minFreqMHz >= maxFreqMHz)
        throw RadioException("Невірний діапазон частот (файл)");
    if (powerW <= 0)
        throw RadioException("Невірна потужність (файл)");
    loadChannels(is);
}
bool RadioStation::operator<(const RadioStation& other) const {
    return powerW < other.powerW;
}
RadioStation& RadioStation::operator+=(const RadioStation& other) {
    channels.insert(channels.end(), other.channels.begin(), other.channels.end());
    return *this;
}
std::ostream& operator<<(std::ostream& os, const RadioStation& rs) {
    rs.print(os);  
    return os;
}
