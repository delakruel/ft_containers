#include <iostream>
#include "vector.hpp"
#include "iterator.hpp"
#include <string>
#include <cstdio>

int main() {
	// std::cout << "privet" << std::endl;

	// ft::vector<int> kek(20, 123);

	// const ft::vector<int> con(30, 777);

	// kek[4] = 20;
	// ft::vector<int> pop(5, 2);
	// std::cout << pop.at(2) << std::endl;
	// ft::vector<int> str;
	// std::cout << str.empty() << " is empty" << std::endl;
	// str.push_back(-5);
	// std::cout << str.empty() << " is not empty" << std::endl;
	// std::cout << str[0] << std::endl;
	// str.push_back(-10);
	// str.push_back(-20);
	// std::cout << str[1] << std::endl;
	// std::cout << str[2] << std::endl;
	// for (int i = 0; i < 10; ++i)
	// 	str.push_back(-5 * i);
	// std::cout << str.size() << ' ' << str.capacity() << std::endl;
	
	// for (int i = 0; i < 15; ++i)
	// 	std::cout << str[i] << " ";
	// std::cout << std::endl;
	// ft::vector<int> lal(str);
	// str.push_back(11);

	// for (int i = 0; i < 15; ++i)
	// 	std::cout << str[i] << " ";
	// std::cout << std::endl;
	// for (int i = 0; i < 15; ++i)
	// 	std::cout << lal[i] << " ";
	// std::cout << std::endl;

	// ft::vector<int> lel;
	// lal = lel;
	// //for (int i = 0; i < 15; ++i)
	// 	std::cout << lal.size() << " " << lal.capacity();
	// std::cout << std::endl;
	ft::vector<int> kek;
	ft::vector<int>::iterator iter = kek.begin();
	printf("%p\n", iter);
	// for (int i = 0; i < 10; ++i)
	// 	kek.push_back(i);
	// ft::vector<int>::iterator first = kek.begin();
	// ft::vector<int>::iterator last = kek.end();

	// ft::vector<int> lol(first, first + 2);
	// for (int i = 0; i < lol.size(); ++i)
	// 	std::cout << lol[i] << ' ';
	// std::cout << last - first << std::endl;
	int *a;
	a = NULL;
	printf("%p\n", a);
}