#include <iostream>
#include <vector>
#include <map>
#include <cstdio>

int main() {
	std::vector<int> kek;
	for (int i = 0; i < 10; ++i)
		kek.push_back(i);
	std::vector<int>::iterator first = kek.begin();
	std::vector<int>::iterator last = first + 3;
	std::cout << *last << std::endl;
	kek.erase(last, last + 2);
	*last = 50;
	for (int i = 0; i < kek.size(); ++i)
		std::cout << kek[i] << ' ';
	std::cout << kek.size() << kek.capacity() << std::endl;
}