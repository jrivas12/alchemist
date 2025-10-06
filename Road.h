// Road.h
#ifndef ROAD_H
#define ROAD_H

#include <string>

class Road {
public:
    std::string name;
    int lanes;
    int speedLimit;

    Road(); 
    Road(const std::string& name, int lanes, int speedLimit);

    virtual ~Road();

    virtual void input();
    virtual void display() const;
};

class Toll : public Road {
public:
    int tollFee;

    Toll(); 
    Toll(const std::string& name, int lanes, int speedLimit, int tollFee);

    void input() override;
    void display() const override;
};

#endif

