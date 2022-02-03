#include <iostream>
#include "vector.hpp"
#include <string>

int main() {
	std::cout << "privet" << std::endl;

	ft::vector<int> kek(20, 123);

	const ft::vector<int> con(30, 777);

	kek[4] = 20;
	// try {
	// 	std::cout << kek.at(4) << std::endl;
	// } catch (std::exception &e) {
	// 	std::cout << e.what() << std::endl;
	// }
	ft::vector<int> str;
	std::cout << str.front() << std::endl;
}