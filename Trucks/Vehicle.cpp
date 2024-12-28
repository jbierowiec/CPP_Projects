#include "Vehicle.h"

Vehicle::Vehicle() : year(0), mpg(0) {}

Vehicle::Vehicle(int year, const std::string& manufacturer, const std::string& model, int mpg)
    : year(year), manufacturer(manufacturer), model(model), mpg(mpg) {}

std::ostream& operator<<(std::ostream& os, const Vehicle& vehicle) {
    os << vehicle.year << " " << vehicle.manufacturer << " " << vehicle.model;
    return os;
}
