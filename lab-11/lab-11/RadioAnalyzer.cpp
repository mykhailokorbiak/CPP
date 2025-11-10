#include "RadioAnalyzer.h"

double RadioAnalyzer::averagePower(const vector<Radiostation*>& v) {
    double sum = 0;
    for (auto p : v) sum += p->power;
    return v.empty() ? 0 : sum / v.size();
}

double RadioAnalyzer::maxRange(const vector<Radiostation*>& v) {
    double m = 0;
    for (auto p : v) m = max(m, p->range());
    return m;
}

