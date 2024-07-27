#pragma once
#include <vector>
#include <string>
#include <filesystem>

class CarStatistics
{
    std::filesystem::path path;

    public:
    CarStatistics(std::filesystem::path path);

    std::vector<std::string> cars() const; // returns all cars

    std::vector<std::string> cities() const; // returns all cities

    std::vector<std::string> cars(std::string city) const; // takes city and returns sold cars

    std::vector<std::string> cities(std::string car) const; // takes car and returns all cities where the car was sold

    std::size_t total_price() const; // returns summed price of all cars

    std::size_t total_price(std::string city) const; // takes a city and returns sum of prices for its cars

    std::size_t total_price(std::string car, std::string city) const; // returns some of prices of car in city

    std::string cheapest(std::string car) const; // returns city where the car was sold the cheapest

    std::vector<std::string> cars_per_city() const; // returns vetor of strings, where string is in fromat "<city_name> <car_count>" (note that cars with the same name are still distinct cars)
};
