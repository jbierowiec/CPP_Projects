#ifndef VEHICLE_H
#define VEHICLE_H

#include <iostream>
#include <string>

class Vehicle {
protected:
    int year;
    std::string manufacturer;
    std::string model;
    int mpg; // Miles per gallon

public:
    Vehicle();
    Vehicle(int year, const std::string& manufacturer, const std::string& model, int mpg);

    friend std::ostream& operator<<(std::ostream& os, const Vehicle& vehicle);
};

#endif
