#pragma once
#include <string>
#include <iostream>
using namespace std;

class Radiostation {
protected:
    string name;
    double frequency;
    double power;     

public:
    Radiostation(string n = "Unknown", double f = 100.0, double p = 10.0);
    virtual ~Radiostation() {}

    virtual void input();
    virtual void show() const;
    virtual double range() const = 0;
};
