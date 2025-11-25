#ifndef RADIOSTATION_H
#define RADIOSTATION_H
#include <string>
#include <vector>
#include <iostream>
#include "RadioException.h"
class RadioStation {
public:
    struct Channel {
        int id;
        double freqMHz;
        std::string description;
    };
protected:
    std::string name;
    std::string location;
    double minFreqMHz{};
    double maxFreqMHz{};
    double powerW{};
    std::vector<Channel> channels;
    void inputChannels();
    void printChannels(std::ostream& os) const;
    void saveChannels(std::ostream& os) const;
    void loadChannels(std::istream& is);
public:
    RadioStation();
    RadioStation(const std::string& n, const std::string& loc,
                 double minF, double maxF, double power);
    virtual ~RadioStation();
    virtual std::string type() const = 0;
    virtual void input();
    virtual void print(std::ostream& os) const;
    virtual void save(std::ostream& os) const;
    virtual void load(std::istream& is);
    bool operator<(const RadioStation& other) const;
    RadioStation& operator+=(const RadioStation& other); 
    friend std::ostream& operator<<(std::ostream& os, const RadioStation& rs);
};
#endif
