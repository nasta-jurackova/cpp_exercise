#include "CarStatistics.hpp"

CarStatistics::CarStatistics(std::filesystem::path path)
{}

std::vector<std::string> CarStatistics::cars()
{
    return {};
}

std::vector<std::string> CarStatistics::cities()
{
    return {};
}

std::vector<std::string> CarStatistics::cars(std::string city)
{
    return {};
}

std::vector<std::string> CarStatistics::cities(std::string car)
{
    return {};
}

std::size_t CarStatistics::total_price()
{
    return 0;
}

std::size_t CarStatistics::total_price(std::string city)
{
    return 0;
}

std::size_t CarStatistics::total_price(std::string car, std::string city)
{
    return 0;
}

std::string CarStatistics::cheapest(std::string car)
{
    return "";
}

std::vector<std::string> CarStatistics::cars_per_city()
{
    return {};
}
