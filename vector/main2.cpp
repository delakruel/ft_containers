#include <iostream>
#include <vector>

int main() {
	std::cout << "privet" << std::endl;

	std::vector<int> kek(20, 123);

	const std::vector<int> con(30, 777);

	kek[4] = 20;
	// try {
	// 	std::cout << kek.at(-20) << std::endl;
	// } catch (std::exception &e) {
	// 	std::cout << e.what() << std::endl;
	// }

	std::vector<int>	test;
	std::cout << kek.back() << std::endl;
}