#include "CarStatistics.hpp"

#include <catch_amalgamated.hpp>
#include <filesystem>
#include <set>
#include <string>

namespace fs = std::filesystem;
using namespace std::literals;

const auto data_path = fs::path(".") / "test_data";

std::pair<std::set<std::string>> load_cars_and_cities(const CarStatistics &cs)
{
    auto cars = cs.cars();
    auto scars = std::set(cars.begin(), cars.end());
    auto cities = cs.cities();
    auto scities = std::set(cities.begin(), cities.end());

    REQUIRE(cars.size() == scars.size());
    REQUIRE(cities.size() == scities.size());

    return {scars, scities};
}

template <typename T>
std::set<T> make_set(const std::vector<T> &vec)
{
    auto svec = std::set(vec.begin(), vec.end());

    REQUIRE(svec.size() == vec.size());
    return svec;
}

TEST_CASE("ONE CITY", "loading")
{
    const CarStatistics cs(data_path / "one_small");

    auto [cars, cities] = load_cars_and_cities(cs);

    REQUIRE(cars == std::set{"bmw"s, "renault"s, "toyota"s, "lexus"s});
    REQUIRE(cities == std::set{"brno"s});

    auto brno_cars = make_set(cs.cars("brno"));
    REQUIRE(brno_cars == std::set{"bmw"s, "renault"s, "toyota"s, "lexus"s});

    for (auto car : {"bmw", "renault", "toyota", "lexus"})
        REQUIRE(cs.cities(car) == std::vector{"brno"s});
}

TEST_CASE("ONE CITY", "statistics")
{
    const CarStatistics cs(data_path / "one_small");

    REQUIRE(cs.total_price() == 2700000);
    REQUIRE(cs.total_price("brno") == 2700000);
    REQUIRE(cs.total_price("brno", "bmw") == 450000);
    REQUIRE(cs.total_price("brno", "renault") == 250000);
    REQUIRE(cs.total_price("brno", "toyota") == 550000);
    REQUIRE(cs.total_price("brno", "lexus") == 1450000);

    REQUIRE(cs.cheapest("bmw") == "brno");
    REQUIRE(cs.cheapest("renault") == "brno");
    REQUIRE(cs.cheapest("toyota") == "brno");
    REQUIRE(cs.cheapest("lexus") == "brno");

    REQUIRE(cs.cars_per_city() == std::vector{"brno 4"s});
}

TEST_CASE("MORE CITIES", "loading")
{
    const CarStatistics cs(data_path / "more_small");

    auto [cars, cities] = load_cars_and_cities(cs);

    REQUIRE(cars == std::set{"bmw"s, "renault"s, "toyota"s, "lexus"s, "skoda"s});
    REQUIRE(cities == std::set{"brno"s, "olomouc"s, "praha"s});

    auto brno_cars = make_set(cs.cars("brno"));
    auto olomouc_cars = make_set(cs.cars("olomouc"));
    auto praha_cars = make_set(cs.cars("praha"));

    REQUIRE(brno_cars == std::set{"bmw"s, "renault"s, "toyota"s, "lexus"s});
    REQUIRE(olomouc_cars == std::set{"bmw"s, "lexus"s, "skoda"s});
    REQUIRE(praha_cars == std::set{"bmw"s, "lexus"s});

    REQUIRE(make_set(cs.cities("bmw")) == std::set{"brno"s, "olomouc"s, "praha"s});
    REQUIRE(make_set(cs.cities("renault")) == std::set{"brno"s});
    REQUIRE(make_set(cs.cities("toyota")) == std::set{"brno"s});
    REQUIRE(make_set(cs.cities("lexus")) == std::set{"brno"s, "olomouc"s, "praha"s});
    REQUIRE(make_set(cs.cities("skoda")) == std::set{"olomouc"s});
}

TEST_CASE("MORE CITIES", "statistics"){
    const CarStatistics cs(data_path / "more_small");

    REQUIRE(cs.total_price() == 6850000);
    REQUIRE(cs.total_price("brno") == 2600000);
    REQUIRE(cs.total_price("praha") == 1900000);
    REQUIRE(cs.total_price("olomouc") == 2350000);

    REQUIRE(cs.total_price("brno", "bmw") == 350000);
    REQUIRE(cs.total_price("brno", "renault") == 250000);
    REQUIRE(cs.total_price("brno", "toyota") == 550000);
    REQUIRE(cs.total_price("brno", "lexus") == 1450000);

    REQUIRE(cs.total_price("praha", "bmw") == 1450000);
    REQUIRE(cs.total_price("praha", "lexus") == 450000);

    REQUIRE(cs.total_price("olomouc", "bmw") == 350000);
    REQUIRE(cs.total_price("olomouc", "lexus") == 1450000);
    REQUIRE(cs.total_price("olomouc", "skoda") == 450000);

    REQUIRE(cs.cheapest("bmw") == "praha");
}