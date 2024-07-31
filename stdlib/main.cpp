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
	// create simple vector
	std::vector<int> vec = {1, 2, 3, 4};

    // apply function
    does_noop(vec);

    // print vector
    print_vector(vec);
}