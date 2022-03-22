#include <iostream>
#include <vector>
#include <map>
#include <cstdio>

int main() {
	
	std::vector<int> kek;
	std::cout << "size kek " << kek.size() << " cap " << kek.capacity() << std::endl;
	for (size_t i = 0; i < kek.size(); ++i) 
		std::cout << kek[i] << ' ';
	std::cout << std::endl;



	std::vector<int> kek2(5, 20);
	std::cout << "size kek2 " << kek2.size() << " cap " << kek2.capacity() << std::endl;
	for (size_t i = 0; i < kek2.size(); ++i) {
		kek2[i] = kek2[i] / 20 + i;
		std::cout << kek2[i] << ' ';
	}
	std::cout << std::endl;

	// //kek2 = kek;

	// // std::cout << "size kek " << kek.size() << " cap " << kek.capacity() << std::endl;
	// // for (size_t i = 0; i < kek.size(); ++i)
	// // 	std::cout << kek[i] << ' ';
	// // std::cout << std::endl;
	
	// kek2.assign(0, 2);

	// std::cout << "size kek2 " << kek2.size() << " cap " << kek2.capacity() << std::endl;
	// for (size_t i = 0; i < kek2.size(); ++i)
	// 	std::cout << kek2[i] << ' ';
	// std::cout << std::endl;
	std::vector<int>::iterator mom = kek2.begin();
	std::vector<int>::iterator mom2 = kek2.end();

	int a = 5;
	int *test1 = &a;
	std::vector<int>::iterator lul(test1);
	printf("%p\n%p\n", &(*lul), test1);
	//printf("%p\n", *lul);
	// printf("%p %p %p \n", mom, mom2, lul);
	// // std::cout << *lul << std::endl;
	// --mom2;
	// std::cout << *mom << std::endl;
	// std::cout << *mom2 << std::endl;
	// std::cout << (mom == mom2) << std::endl;
}