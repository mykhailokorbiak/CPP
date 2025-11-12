#pragma once
#include "Radiostation.h"

class BaseStation : public Radiostation {
    double antennaHeight;

public:
    BaseStation(string n="Base", double f=100, double p=50, double h=30);
    void input() override;
    void show() const override;
    double range() const override;
};
