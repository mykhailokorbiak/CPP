#include "AmpModules.h"
#include <iostream>
AmpModuleA::AmpModuleA(const std::string& name,
                       const OperationalAmplifier& amp)
    : name(name), amp(amp)
{
    std::cout << "[Ctor] AmpModuleA \"" << name << "\" створено\n";
}
AmpModuleA::~AmpModuleA()
{
    std::cout << "[Dtor] AmpModuleA \"" << name << "\" знищено\n";
}
AmpModuleB::AmpModuleB(const std::string& name,
                       const OperationalAmplifier& amp)
    : name(name), amp(amp)
{
    std::cout << "[Ctor] AmpModuleB \"" << name << "\" створено\n";
}
AmpModuleB::~AmpModuleB()
{
    std::cout << "[Dtor] AmpModuleB \"" << name << "\" знищено\n";
}
