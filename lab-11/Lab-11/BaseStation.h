#pragma once
#include "Radiostation.h"

class BaseStation : public Radiostation {
    double antennaHeight;

public:
    BaseStation(string n = "Base", double f = 100.0, double p = 50.0, double h = 25.0);
    void input() override;
    void show() const override;
    double range() const override;
};
