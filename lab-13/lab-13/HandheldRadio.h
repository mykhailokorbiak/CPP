#ifndef HANDHELDRADIO_H
#define HANDHELDRADIO_H
#include "RadioStation.h"
class HandheldRadio : public RadioStation {
    double batteryCapacityAh{};
    double weightKg{};
    bool hasDisplay{};
public:
    HandheldRadio();
    HandheldRadio(const std::string& n, const std::string& loc,
                  double minF, double maxF, double power,
                  double capacity, double weight, bool display);

    std::string type() const override { return "Портативна рація"; }
    void input() override;
    void print(std::ostream& os) const override;
    void save(std::ostream& os) const override;
    void load(std::istream& is) override;
};
#endif

