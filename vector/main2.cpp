#include <iostream>
#include <vector>

int main() {
	std::vector<int> kek;
	std::cout << "size kek " << kek.size() << " cap " << kek.capacity() << std::endl;
	for (size_t i = 0; i < kek.size(); ++i)
		std::cout << kek[i] << ' ';
	std::cout << std::endl;



	std::vector<int> kek2(5, 20);
	std::cout << "size kek2 " << kek2.size() << " cap " << kek2.capacity() << std::endl;
	for (size_t i = 0; i < kek2.size(); ++i)
		std::cout << kek2[i] << ' ';
	std::cout << std::endl;

	//kek2 = kek;

	// std::cout << "size kek " << kek.size() << " cap " << kek.capacity() << std::endl;
	// for (size_t i = 0; i < kek.size(); ++i)
	// 	std::cout << kek[i] << ' ';
	// std::cout << std::endl;
	
	kek2.assign(0, 2);

	std::cout << "size kek2 " << kek2.size() << " cap " << kek2.capacity() << std::endl;
	for (size_t i = 0; i < kek2.size(); ++i)
		std::cout << kek2[i] << ' ';
	std::cout << std::endl;
}