#include <iostream>
#include "vector.hpp"

int main() {
	std::cout << "privet" << std::endl;

	ft::vector<int> kek(20, 123);

	const ft::vector<int> con(30, 777);

	kek[4] = 20;
	std::cout << kek.at(4) << std::endl;
}