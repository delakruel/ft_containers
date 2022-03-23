#include <iostream>
#include <vector>
#include <map>
#include <cstdio>

int main() {
	std::vector<int> kek;
	std::vector<int>::iterator iter = kek.begin();
	//std::cout << iter << std::endl;
	printf("%p\n", iter);
	kek.insert(kek.begin(), 5);
	std::cout << kek.capacity() << std::endl;
}