#pragma once

#include <vector>
#include <numeric>
#include <algorithm>

template<typename T>
std::size_t count_trues(std::vector<T> vec)
{
    auto add_bool = [](std::size_t acc, const T& to_add)
    {
        bool bool_r = bool(to_add);
        if(bool_r)
            return ++acc;
        return acc;
    };
    return std::accumulate(vec.begin(), vec.end(), 0, add_bool);
}

template<typename T>
T sum_it_up(std::vector<T> vec)
{
    return std::accumulate(vec.begin(), vec.end());
}

template<typename T>
void increment(std::vector<T> vec)
{
    std::transform(vec.begin(), vec.end(), vec.begin(), [](T& i){++i;});
}

template<typename T>
std::pair<T, T> find_bounds(std::vector<T> vec)
{
    return std::minmax_element(vec.begin(), vec.end());
}
