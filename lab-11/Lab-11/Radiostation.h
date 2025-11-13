#pragma once
#include <iostream>
#include <string>
using namespace std;

class RadioAnalyzer; // оголошення друга

class Radiostation {
protected:
    string name;
    double frequency;
  

public:
    Radiostation(string n = "Unknown", double f = 100.0, double p = 10.0);
    virtual ~Radiostation() {}
    double power;

    virtual void input();
    virtual void show() const;
    virtual double range() const = 0; // чисто віртуальна

    friend class RadioAnalyzer; // дружній клас
};
