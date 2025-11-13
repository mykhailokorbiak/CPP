#include "FriendAnalyzer.h"

double FriendAnalyzer::averagePower(const vector<shared_ptr<Radiostation>> &stations) {
    if (stations.empty()) return 0;
    double sum = 0;
    for (auto &s : stations) sum += s -> power;
    return sum / stations.size();
}

double FriendAnalyzer::maxRange(const vector<shared_ptr<Radiostation>> &stations) {
    double maxVal = 0;
    for (auto &s : stations)
        if (s->range() > maxVal)
            maxVal = s->range();
    return maxVal;
}
