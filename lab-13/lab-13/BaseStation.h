#ifndef BASESTATION_H
#define BASESTATION_H
#include "RadioStation.h"
class BaseStation : public RadioStation {
    int maxClients{};
    double antennaHeight{};
public:
    BaseStation();
    BaseStation(const std::string& n, const std::string& loc,
                double minF, double maxF, double power,
                int clients, double height);

    std::string type() const override { return "Базова станція"; }
    void input() override;
    void print(std::ostream& os) const override;
    void save(std::ostream& os) const override;
    void load(std::istream& is) override;
};
#endif
