#include "CarStatistics.hpp"
#include <fstream>
#include <set>
#include <format>

CarStatistics::CarStatistics(const std::filesystem::path &path)
{
    for(auto const &dir_entry : std::filesystem::directory_iterator(path))
    {
        std::vector<std::tuple<unsigned, std::string, unsigned>> table;
        std::ifstream infile(dir_entry.path());
        std::string line;
        std::getline(infile, line);
        while(std::getline(infile, line))
        {
            std::string deliminer = ",";
            std::string year = line.substr(0, line.find(deliminer));
            line = line.substr(line.find(deliminer) + 1);
            std::string car = line.substr(0, line.find(deliminer));
            std::string price = line.substr(line.find(deliminer) + 1);
            table.emplace_back(std::stoi(year), car, std::stoi(price));
        }
        data[dir_entry.path().stem()] = table;
    }
}

std::vector<std::string> CarStatistics::cars() const
{
    std::set<std::string> result;
    for (const auto & [city, table] : data)
    {
        for (const auto & [year, car, price] : table)
        {
            result.insert(car);
        }
    }
    return std::vector<std::string>(result.begin(), result.end());
}

std::vector<std::string> CarStatistics::cities() const
{
    std::vector<std::string> result;
    for (const auto & [city, table] : data)
    {
        result.push_back(city);
    }
    return result;
}

std::vector<std::string> CarStatistics::cars(const std::string &city) const
{
    std::set<std::string> result;
    auto &table = data.at(city);
    for (const auto & [year, car, price] : table)
    {
        result.insert(car);
    }
    return std::vector<std::string>(result.begin(), result.end());
}

std::vector<std::string> CarStatistics::cities(const std::string &to_find) const
{
    std::set<std::string> result;
    for (const auto & [city, table] : data)
    {
        for (const auto & [year, car, price] : table)
        {
            if(car == to_find)
                result.insert(city);
        }
    }
    return std::vector<std::string>(result.begin(), result.end());
}

std::size_t CarStatistics::total_price() const
{
    std::size_t result = 0;
    for (const auto & [city, table] : data)
    {
        for (const auto & [year, car, price] : table)
        {
            result += price;
        }
    }
    return result;
}

std::size_t CarStatistics::total_price(const std::string &city) const
{
    std::size_t result = 0;
    auto &table = data.at(city);
    for (const auto & [year, car, price] : table)
    {
        result += price;
    }
    return result;
}

std::size_t CarStatistics::total_price(const std::string &to_find, const std::string &city) const
{
    std::size_t result = 0;
    auto &table = data.at(city);
    for (const auto & [year, car, price] : table)
    {
        if(car == to_find)
            result += price;
    }
    return result;
}

std::string CarStatistics::cheapest(const std::string &to_find) const
{
    std::string result = "";
    unsigned curr_price = std::numeric_limits<unsigned>::max();
    for (const auto & [city, table] : data)
    {
        for (const auto & [year, car, price] : table)
        {
            if(car == to_find && price <= curr_price)
            {
                curr_price = price;
                result = city;
            }
        }
    }
    return result;
}

std::vector<std::string> CarStatistics::cars_per_city() const
{
    std::vector<std::string> result;
    for (const auto & [city, table] : data)
    {
        result.push_back(std::format("{} {}", city, table.size()));
    }
    return {};
}
