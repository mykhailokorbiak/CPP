#pragma once
#include <vector>
#include "Radiostation.h"

class RadioAnalyzer {
public:
    static double averagePower(const vector<Radiostation*>& v);
    static double maxRange(const vector<Radiostation*>& v);
};

