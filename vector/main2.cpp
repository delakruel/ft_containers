#include <iostream>
#include <vector>
#include <map>
#include <cstdio>
#include <type_traits>

int main() {
	std::vector<int> kek;
	std::vector<int>::iterator iter = kek.begin();
	for (int i = 0; i < 10; i++) 
		kek.push_back(i);
	std::cout << kek.capacity() << std::endl;
	kek.insert(kek.end() - 1, 7, 10);
	for (int i = 0; i < kek.size(); i++)
		std::cout << kek[i] << ' ' ; 
	std::cout << kek.capacity() << std::endl;
	kek.insert(kek.end() - 1, 18, 10);
	std::cout << kek.capacity() << std::endl;
	std::cout << std::is_integral<int>::value << std::endl;
}