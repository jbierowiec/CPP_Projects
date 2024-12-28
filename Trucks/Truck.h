#ifndef TRUCK_H
#define TRUCK_H

#include "Vehicle.h"

class Truck : public Vehicle {
private:
    int towing_capacity;

public:
    Truck();
    Truck(int year, const std::string& manufacturer, const std::string& model, int mpg, int towing_capacity);
};

#endif
