#include <iostream>
#include <vector>

#include "impl.hpp"

void print_vector(const auto& vec) {
	std::cout << "[ ";
	for (const auto& el : vec)
		std::cout << el << " ";
	std::cout << "]\n";
}

int main() {
	std::cout << "count trues:\n";
	std::vector<int> vec1 = {0, 1, 1, 0, 0, 1};
	print_vector(vec1);
    std::cout << count_trues(vec1) << "\n";
	std::cout << "\n";

	std::cout << "sum it up:\n";
	std::vector<int> vec2 = {1, 1, 1, 2, 3};
	print_vector(vec2);
	std::cout << sum_it_up(vec2);
	std::cout << "\n";

	std::cout << "increment:\n";
	std::vector<int> vec3 = {0, 1, 2, 3};
	print_vector(vec3);
	increment(vec3);
	print_vector(vec3);
	std::cout << "\n";

	std::cout << "find bounds:\n";
	std::vector<int> vec4 = {3, 2, 1, 4, 6, 5};
	print_vector(vec4);
	std::cout << find_bounds(vec4).first << ", " << find_bounds(vec4).second << "\n";
}
