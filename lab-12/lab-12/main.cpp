#include <iostream>
#include <vector>
#include <algorithm>
#include "MyString.h"

int main() {
    int n;
    std::cout << "Кількість рядків: ";
    std::cin >> n;
    std::cin.ignore();

    std::vector<MyString> arr(n);

    for (int i = 0; i < n; i++) {
        std::cout << "Рядок #" << i + 1 << ": ";
        arr[i].input();
    }

    // Сортування за зростанням
    std::sort(arr.begin(), arr.end(),
              [](const MyString& a, const MyString& b) {
                  return !(a >= b);    // тобто "a < b"
              });

    std::cout << "\nВідсортовані рядки:\n";
    for (const auto& r : arr) {
        std::cout << r << "\n";
    }

    char ch;
    std::cout << "\nВведіть символ, який треба вилучити з кожного рядка: ";
    std::cin >> ch;

    std::cout << "\nРезультат після видалення '" << ch << "':\n";
    for (auto& r : arr) {
        MyString modified = r - ch;
        std::cout << modified << "\n";
    }

    return 0;
}
