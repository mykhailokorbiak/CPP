#include <iostream>
#include <vector>
#include <fstream>
#include "BaseStation.h"
#include "HandheldRadio.h"
void saveToFile(const std::vector<RadioStation*>& stations,
                const std::string& filename)
{
    std::ofstream file(filename);
    if (!file)
        throw RadioException("Не вдалося відкрити файл для запису");
    file << stations.size() << '\n';
    for (const auto* st : stations) {
        if (dynamic_cast<const BaseStation*>(st))
            file << 0 << '\n';
        else if (dynamic_cast<const HandheldRadio*>(st))
            file << 1 << '\n';
        else
            throw RadioException("Невідомий тип радіостанції при збереженні");
        st->save(file);
    }
}
void clearVector(std::vector<RadioStation*>& stations) {
    for (auto* st : stations)
        delete st;
    stations.clear();
}
void loadFromFile(std::vector<RadioStation*>& stations,
                  const std::string& filename)
{
    std::ifstream file(filename);
    if (!file)
        throw RadioException("Не вдалося відкрити файл для читання");
    clearVector(stations);
    std::size_t count;
    if (!(file >> count))
        throw RadioException("Помилка читання кількості об'єктів з файлу");
    for (std::size_t i = 0; i < count; ++i) {
        int type;
        if (!(file >> type))
            throw RadioException("Помилка читання типу об'єкта з файлу");
        RadioStation* st = nullptr;
        if (type == 0)
            st = new BaseStation();
        else if (type == 1)
            st = new HandheldRadio();
        else
            throw RadioException("Невідомий тип об'єкта у файлі");
        st->load(file);
        stations.push_back(st);
    }
}
void showMenu() {
    std::cout << "\n--- Меню ---\n"
              << "1 - Додати базову станцію\n"
              << "2 - Додати портативну рацію\n"
              << "3 - Показати всі об'єкти\n"
              << "4 - Зберегти у файл\n"
              << "5 - Завантажити з файлу\n"
              << "6 - Порівняти дві станції по потужності\n"
              << "7 - Об'єднати канали двох станцій (+=)\n"
              << "0 - Вихід\n"
              << "Ваш вибір: ";
}
int main() {
    std::vector<RadioStation*> stations;
    const std::string filename = "radio_data.txt";
    bool running = true;
    while (running) {
        try {
            showMenu();
            int choice;
            if (!(std::cin >> choice)) {
                std::cerr << "Помилка вводу, завершуємо.\n";
                break;
            }
            switch (choice) {
            case 1: {
                RadioStation* st = new BaseStation();
                st->input();
                stations.push_back(st);
                break;
            }
            case 2: {
                RadioStation* st = new HandheldRadio();
                st->input();
                stations.push_back(st);
                break;
            }
            case 3: {
                if (stations.empty()) {
                    std::cout << "Список порожній.\n";
                } else {
                    std::cout << "\n=== Список радіостанцій ===\n";
                    for (std::size_t i = 0; i < stations.size(); ++i) {
                        std::cout << "\n# " << i << '\n';
                        std::cout << *stations[i];
                    }
                }
                break;
            }
            case 4:
                saveToFile(stations, filename);
                std::cout << "Дані збережено у файл '" << filename << "'.\n";
                break;
            case 5:
                loadFromFile(stations, filename);
                std::cout << "Дані завантажено з файлу '" << filename << "'.\n";
                break;
            case 6: {
                if (stations.size() < 2) {
                    std::cout << "Потрібно хоча б 2 об'єкти.\n";
                    break;
                }
                std::size_t a, b;
                std::cout << "Індекси двох станцій (через пробіл): ";
                std::cin >> a >> b;
                if (a >= stations.size() || b >= stations.size())
                    throw RadioException("Невірні індекси для порівняння");
                if (*stations[a] < *stations[b])
                    std::cout << "Станція #" << a << " менш потужна, ніж #" << b << "\n";
                else if (*stations[b] < *stations[a])
                    std::cout << "Станція #" << a << " більш потужна, ніж #" << b << "\n";
                else
                    std::cout << "Станції мають однакову потужність.\n";
                break;
            }
            case 7: {
                if (stations.size() < 2) {
                    std::cout << "Потрібно хоча б 2 об'єкти.\n";
                    break;
                }
                std::size_t a, b;
                std::cout << "Індекси станцій A і B (A += B): ";
                std::cin >> a >> b;
                if (a >= stations.size() || b >= stations.size())
                    throw RadioException("Невірні індекси для операції +=");
                *stations[a] += *stations[b];
                std::cout << "Канали станції #" << b << " додано до станції #" << a << ".\n";
                break;
            }
            case 0:
                running = false;
                break;

            default:
                std::cout << "Невірний пункт меню.\n";
                break;
            }
        }
        catch (const RadioException& ex) {
            std::cerr << "ПОМИЛКА (RadioException): " << ex.what() << '\n';
            std::cin.clear();
            std::cin.ignore(10000, '\n');
        }
        catch (const std::exception& ex) {
            std::cerr << "Стандартний виняток: " << ex.what() << '\n';
            std::cin.clear();
            std::cin.ignore(10000, '\n');
        }
    }
    clearVector(stations);
    std::cout << "Завершення роботи.\n";
    return 0;
}
