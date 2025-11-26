#ifndef AMP_MODULES_H
#define AMP_MODULES_H
#include <memory>
#include <string>
#include "OperationalAmplifier.h"
class AmpModuleB;
class AmpModuleA {
public:
    std::string name;
    OperationalAmplifier amp;
    std::shared_ptr<AmpModuleB> moduleB;
    AmpModuleA(const std::string& name,
               const OperationalAmplifier& amp);
    ~AmpModuleA();
};
class AmpModuleB {
public:
    std::string name;
    OperationalAmplifier amp;
    std::weak_ptr<AmpModuleA> moduleA;
    AmpModuleB(const std::string& name,
               const OperationalAmplifier& amp);
    ~AmpModuleB();
};
#endif 
