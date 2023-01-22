#include <iostream>

#include "whatever.hpp"


int
main()
{
	int i1 = 42, i2 = 10;
	float f1 = 4.2f, f2 = -1.0f;
	char c1 = '*', c2 = 'B';

	printPair<int>(i1, i2);
	printPair<float>(f1, f2);
	printPair<char>(c1, c2);

	std::cout << std::endl;

	printMax<int>(i1, i2);
	printMax<float>(f1, f2);
	printMax<char>(c1, c2);

	std::cout << std::endl;

	printMin<int>(i1, i2);
	printMin<float>(f1, f2);
	printMin<char>(c1, c2);

	std::cout << std::endl;

	std::cout << "Swapping" << std::endl;
	swap<int>(i1, i2);
	swap<float>(f1, f2);
	swap<char>(c1, c2);

	std::cout << std::endl;

	printPair<int>(i1, i2);
	printPair<float>(f1, f2);
	printPair<char>(c1, c2);

	std::cout << std::endl;

	printMax<int>(i1, i2);
	printMax<float>(f1, f2);
	printMax<char>(c1, c2);

	std::cout << std::endl;

	printMin<int>(i1, i2);
	printMin<float>(f1, f2);
	printMin<char>(c1, c2);

	return 0;
}
