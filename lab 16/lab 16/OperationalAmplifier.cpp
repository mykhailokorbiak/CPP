#include "OperationalAmplifier.h"
#include <iostream>
OperationalAmplifier::OperationalAmplifier()
    : gain(1.0), supplyVoltage(5.0), inputs(2)
{
    std::cout << "[Ctor] Створено операційний підсилювач (за замовчуванням)\n";
}
OperationalAmplifier::OperationalAmplifier(double gain, double supplyVoltage, int inputs)
    : gain(gain), supplyVoltage(supplyVoltage), inputs(inputs)
{
    std::cout << "[Ctor] Створено операційний підсилювач: "
              << toString() << '\n';
}
OperationalAmplifier::~OperationalAmplifier()
{
    std::cout << "[Dtor] Знищено операційний підсилювач: "
              << toString() << '\n';
}
double OperationalAmplifier::getGain() const {
    return gain;
}
void OperationalAmplifier::setGain(double g) {
    gain = g;
}
double OperationalAmplifier::getSupplyVoltage() const {
    return supplyVoltage;
}
void OperationalAmplifier::setSupplyVoltage(double v) {
    supplyVoltage = v;
}
int OperationalAmplifier::getInputs() const {
    return inputs;
}
void OperationalAmplifier::setInputs(int n) {
    inputs = n;
}
std::string OperationalAmplifier::toString() const {
    return "Kус=" + std::to_string(gain) +
           ", Uжив=" + std::to_string(supplyVoltage) +
           " В, входів=" + std::to_string(inputs);
}
void OperationalAmplifier::print() const {
    std::cout << "Операційний підсилювач: " << toString() << '\n';
}
