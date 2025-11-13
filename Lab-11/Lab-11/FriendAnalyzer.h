#pragma once
#include <vector>
#include <memory>
#include "Radiostation.h"

class  FriendAnalyzer {
public:
    static double averagePower(const vector<shared_ptr<Radiostation>> &stations);
    static double maxRange(const vector<shared_ptr<Radiostation>> &stations);
};
