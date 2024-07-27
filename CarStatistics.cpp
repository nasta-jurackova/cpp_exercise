#include "CarStatistics.hpp"

CarStatistics::CarStatistics(std::filesystem::path path)
{}

std::vector<std::string> CarStatistics::cars() const
{
    return {};
}

std::vector<std::string> CarStatistics::cities() const
{
    return {};
}

std::vector<std::string> CarStatistics::cars(std::string city) const
{
    return {};
}

std::vector<std::string> CarStatistics::cities(std::string car) const
{
    return {};
}

std::size_t CarStatistics::total_price() const
{
    return 0;
}

std::size_t CarStatistics::total_price(std::string city) const
{
    return 0;
}

std::size_t CarStatistics::total_price(std::string car, std::string city) const
{
    return 0;
}

std::string CarStatistics::cheapest(std::string car) const
{
    return "";
}

std::vector<std::string> CarStatistics::cars_per_city() const
{
    return {};
}
