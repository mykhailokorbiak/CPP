#ifndef OPERATIONAL_AMPLIFIER_H
#define OPERATIONAL_AMPLIFIER_H
#include <string>
class OperationalAmplifier {
private:
    double gain;
    double supplyVoltage;
    int inputs;
public:
    OperationalAmplifier();
    OperationalAmplifier(double gain, double supplyVoltage, int inputs);
    ~OperationalAmplifier();
    double getGain() const;
    void setGain(double g);
    double getSupplyVoltage() const;
    void setSupplyVoltage(double v);
    int getInputs() const;
    void setInputs(int n);
    std::string toString() const;
    void print() const;
};
#endif 
