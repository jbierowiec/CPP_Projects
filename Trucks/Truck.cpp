#include "Truck.h"

Truck::Truck() : Vehicle(), towing_capacity(0) {}

Truck::Truck(int year, const std::string& manufacturer, const std::string& model, int mpg, int towing_capacity)
    : Vehicle(year, manufacturer, model, mpg), towing_capacity(towing_capacity) {}
