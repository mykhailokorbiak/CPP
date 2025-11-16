#include "MyString.h"

MyString::MyString() : s("") {}

MyString::MyString(const std::string& str) : s(str) {}

void MyString::input() {
    std::cout << "Введіть рядок: ";
    std::getline(std::cin, s);

    // Для Xcode — інколи getline перескакує перший рядок, дублюємо
    if (s.empty()) std::getline(std::cin, s);
}

void MyString::print() const {
    std::cout << s;
}

bool MyString::operator>=(const MyString& other) const {
    return s >= other.s;
}

MyString MyString::operator-(char ch) const {
    std::string result;
    for (char c : s) {
        if (c != ch) result += c;
    }
    return MyString(result);
}

const std::string& MyString::get() const {
    return s;
}

std::ostream& operator<<(std::ostream& os, const MyString& ms) {
    os << ms.s;
    return os;
}
