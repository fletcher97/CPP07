#include "iter.hpp"

int
main() {
	// Int
	std::cout << "Testing  with ints:" << std::endl;
	int iArr[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

	iter<int>(iArr, 10, &print);

	std::cout << std::endl;

	iter<int>(iArr, 10, &add1);
	std::cout << "Adding one to every element"<< std::endl;

	std::cout << std::endl;

	iter<int>(iArr, 10, &print);

	std::cout << std::endl;

	// Float
	std::cout << "Testing  with floats:" << std::endl;
	float fArr[10] = {0.5f, 1.5f, 2.5f, 3.5f, 4.5f, 5.5f, 6.5f, 7.5f, 8.5f, 9.5f};

	iter<float>(fArr, 10, &print);

	std::cout << std::endl;

	iter<float>(fArr, 10, &add1);
	std::cout << "Adding one to every element"<< std::endl;

	std::cout << std::endl;

	iter<float>(fArr, 10, &print);

	std::cout << std::endl;




}
