#pragma once
#include <vector>
#include <string>
#include <filesystem>

class CarStatistics
{
    std::filesystem::path path;

    public:
    CarStatistics(std::filesystem::path path);

    std::vector<std::string> cars(); // returns all cars

    std::vector<std::string> cities(); // returns all cities

    std::vector<std::string> cars(std::string city); // takes city and returns sold cars

    std::vector<std::string> cities(std::string car); // takes car and returns all cities where the car was sold

    std::size_t total_price(); // returns summed price of all cars

    std::size_t total_price(std::string city); // takes a city and returns sum of prices for its cars

    std::size_t total_price(std::string car, std::string city); // returns some of prices of car in city

    std::string cheapest(std::string car); // returns city where the car was sold the cheapest

    std::vector<std::string> cars_per_city(); // returns vetor of strings, where string is in fromat "<city_name> <car_count>" (note that cars with the same name are still distinct cars)
};
