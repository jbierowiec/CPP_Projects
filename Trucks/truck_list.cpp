#include <iostream>
#include <fstream>
#include <vector>
#include "Truck.h"

std::vector<Truck> readTrucksFromFile(const std::string& filename) {
    std::vector<Truck> trucks;
    std::ifstream file(filename);

    if (!file) {
        std::cerr << "Error: Could not open file." << std::endl;
        return trucks;
    }

    std::string line;
    while (std::getline(file, line)) {
        if (line == "---") continue;

        int year = std::stoi(line);
        std::string manufacturer;
        std::getline(file, manufacturer);
        std::string model;
        std::getline(file, model);
        int mpg;
        file >> mpg;
        file.ignore();
        int towing_capacity;
        file >> towing_capacity;
        file.ignore();

        Truck truck(year, manufacturer, model, mpg, towing_capacity);
        trucks.push_back(truck);
    }

    file.close();
    return trucks;
}

int main() {
    std::vector<Truck> trucks = readTrucksFromFile("trucks.txt");

    if (trucks.empty()) {
        std::cout << "No trucks found in the file." << std::endl;
        return 0;
    }

    for (size_t i = 0; i < trucks.size(); i++) {
        std::cout << trucks[i] << std::endl;
    }

    return 0;
}
