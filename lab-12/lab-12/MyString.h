#pragma once
#include <string>
#include <iostream>

class MyString {
private:
    std::string s;

public:
    MyString();
    MyString(const std::string& str);

    void input();
    void print() const;

    bool operator>=(const MyString& other) const;
    MyString operator-(char ch) const;

    const std::string& get() const;

    friend std::ostream& operator<<(std::ostream& os, const MyString& ms);
};
