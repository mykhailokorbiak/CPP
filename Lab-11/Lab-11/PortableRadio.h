#pragma once
#include "Radiostation.h"

class PortableRadio : public Radiostation {
    int batteryCapacity;

public:
    PortableRadio(string n = "Portable", double f = 100.0, double p = 5.0, int b = 2000);
    void input() override;
    void show() const override;
    double range() const override;
};
