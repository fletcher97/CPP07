#include <iostream>
#include <cstdlib>

#include "Array.tpp"
#include "data.hpp"

#define MAX_VAL 750
void
theirTests() {
	Array<int> numbers(MAX_VAL);
	int* mirror = new int[MAX_VAL];
	std::srand(time(NULL));
	for (int i = 0; i < MAX_VAL; i++)
	{
		const int value = std::rand();
		numbers[i] = value;
		mirror[i] = value;
	}
	//SCOPE
	{
		Array<int> tmp = numbers;
		Array<int> test(tmp);
	}

	for (int i = 0; i < MAX_VAL; i++)
	{
		if (mirror[i] != numbers[i])
		{
			std::cerr << "didn't save the same value!!" << std::endl;
			return ;
		}
	}
	try
	{
		numbers[-2] = 0;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		numbers[MAX_VAL] = 0;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	for (int i = 0; i < MAX_VAL; i++)
	{
		numbers[i] = rand();
	}
	delete [] mirror;
}

void
initTest() {

	std::cout << "########################" << std::endl;
	std::cout << "###### INIT TESTS ######" << std::endl;
	std::cout << "########################" << std::endl;

	std::cout << std::endl;

	{
		std::cout << "Init int array with no params" << std::endl;
		Array<int> a1;
		std::cout << "a1: " << a1 << std::endl;
	}

	std::cout << std::endl;

	{
		std::cout << "Init data array with no params" << std::endl;
		Array<data_t> a1;
		std::cout << "a1: " << a1 << std::endl;
	}

	std::cout << std::endl;

	{
		std::cout << "Init int array with 5 elems" << std::endl;
		Array<int> a1(5);
		std::cout << "a1: " << a1 << std::endl;
	}

	std::cout << std::endl;

	{
		std::cout << "Init data array with 5 elems" << std::endl;
		Array<data_t> a1(5);
		std::cout << "a1: " << a1 << std::endl;
	}

	std::cout << std::endl;

	{
		std::cout << "Init copy int array with no params" << std::endl;
		Array<int> a1;
		Array<int> a2(a1);
		std::cout << "a1: " << a1 << std::endl;
		std::cout << "a2: " << a2 << std::endl;
	}

	std::cout << std::endl;

	{
		std::cout << "Init copy data array with no params" << std::endl;
		Array<data_t> a1;
		Array<data_t> a2(a1);
		std::cout << "a1: " << a1 << std::endl;
		std::cout << "a2: " << a2 << std::endl;
	}

	std::cout << std::endl;

	{
		std::cout << "Init copy int array with 5 elems" << std::endl;
		Array<int> a1(5);
		Array<int> a2(a1);
		std::cout << "a1: " << a1 << std::endl;
		std::cout << "a2: " << a2 << std::endl;
	}

	std::cout << std::endl;

	{
		std::cout << "Init copy data array with 5 elems" << std::endl;
		Array<data_t> a1(5);
		Array<data_t> a2(a1);
		std::cout << "a1: " << a1 << std::endl;
		std::cout << "a2: " << a2 << std::endl;
	}

	std::cout << std::endl;

	{
		std::cout << "Init assignment int array with 5 elems" << std::endl;
		Array<int> a1(5);
		Array<int> a2 = a1;
		std::cout << "a1: " << a1 << std::endl;
		std::cout << "a2: " << a2 << std::endl;
	}

	std::cout << std::endl;

	{
		std::cout << "Init assignment data array with 5 elems" << std::endl;
		Array<data_t> a1(5);
		Array<data_t> a2 = a1;
		std::cout << "a1: " << a1 << std::endl;
		std::cout << "a2: " << a2 << std::endl;
	}

}

void
modTest() {

	std::cout << "#######################" << std::endl;
	std::cout << "###### MOD TESTS ######" << std::endl;
	std::cout << "#######################" << std::endl;

	std::cout << std::endl;

	{
		std::cout << "Mod int array with 5 elems (set)" << std::endl;
		Array<int> a1(5);
		std::cout << "a1 before: " << a1 << std::endl;
		a1.set(10);
		std::cout << "a1 after: " << a1 << std::endl;
	}

	std::cout << std::endl;

	{
		std::cout << "Init copy data array with 5 elems (set)" << std::endl;
		Array<data_t> a1(5);
		std::cout << "a1 before: " << a1 << std::endl;
		data_t d; d.i= 10; d.c= 'c';
		a1.set(d);
		std::cout << "a1 after: " << a1 << std::endl;
	}

	std::cout << std::endl;

	{
		std::cout << "Mod int array with 5 elems (operator[])" << std::endl;
		Array<int> a1(5);
		std::cout << "a1 before: " << a1 << std::endl;
		for (unsigned int i = 0; i < a1.size(); i++)
			a1[i] = i;
		std::cout << "a1 after: " << a1 << std::endl;
	}

	std::cout << std::endl;

	{
		std::cout << "Init copy data array with 5 elems (operator[])" << std::endl;
		Array<data_t> a1(5);
		std::cout << "a1 before: " << a1 << std::endl;
		data_t d; d.i= 0; d.c= 'a';
		for (unsigned int i = 0; i < a1.size(); i++, d.i++, d.c++)
			a1[i] = d;
		std::cout << "a1 after: " << a1 << std::endl;
	}

	std::cout << std::endl;

	{
		std::cout << "Mod int array with 5 elems (operator[]) after copy" << std::endl;
		Array<int> a1(5);
		Array<int> a2(a1);
		std::cout << "a1 before: " << a1 << std::endl;
		std::cout << "a2 before: " << a2 << std::endl;
		for (unsigned int i = 0; i < a1.size(); i++)
			a1[i] = i;
		std::cout << "a1 after: " << a1 << std::endl;
		std::cout << "a2 after: " << a2 << std::endl;
	}

	std::cout << std::endl;

	{
		std::cout << "Init copy data array with 5 elems (operator[]) after copy" << std::endl;
		Array<data_t> a1(5);
		Array<data_t> a2(a1);
		std::cout << "a1 before: " << a1 << std::endl;
		std::cout << "a2 before: " << a2 << std::endl;
		data_t d; d.i= 0; d.c= 'a';
		for (unsigned int i = 0; i < a1.size(); i++, d.i++, d.c++)
			a1[i] = d;
		std::cout << "a1 after: " << a1 << std::endl;
		std::cout << "a2 after: " << a2 << std::endl;
	}

}

void
errTest() {

	std::cout << "#######################" << std::endl;
	std::cout << "###### ERR TESTS ######" << std::endl;
	std::cout << "#######################" << std::endl;

	std::cout << std::endl;

	{
		std::cout << "Access empty int array" << std::endl;
		Array<int> a1;
		try {
			std::cout << a1[0] << std::endl;
		} catch (std::exception& e) {
			std::cout << "[Error]: " << e.what() << std::endl;
		}

	}

	std::cout << std::endl;

	{
		std::cout << "Access empty data array" << std::endl;
		Array<int> a1;
		try {
			std::cout << a1[0] << std::endl;
		} catch (std::exception& e) {
			std::cout << "[Error]: " << e.what() << std::endl;
		}
	}

	std::cout << std::endl;

	{
		std::cout << "Access out of bounds int array" << std::endl;
		Array<int> a1(5);
		try {
			std::cout << a1[5] << std::endl;
		} catch (std::exception& e) {
			std::cout << "[Error]: " << e.what() << std::endl;
		}
	}

	std::cout << std::endl;

	{
		std::cout << "Access out of bounds data array" << std::endl;
		Array<int> a1(5);
		try {
			std::cout << a1[5] << std::endl;
		} catch (std::exception& e) {
			std::cout << "[Error]: " << e.what() << std::endl;
		}
	}

	std::cout << std::endl;

	{
		std::cout << "Access negative int array" << std::endl;
		Array<int> a1(5);
		try {
			std::cout << a1[-1] << std::endl;
		} catch (std::exception& e) {
			std::cout << "[Error]: " << e.what() << std::endl;
		}
	}

	std::cout << std::endl;

	{
		std::cout << "Access negative data array" << std::endl;
		Array<int> a1(5);
		try {
			std::cout << a1[-1] << std::endl;
		} catch (std::exception& e) {
			std::cout << "[Error]: " << e.what() << std::endl;
		}
	}
}

void
myTests() {
	initTest();
	std::cout << std::endl;
	modTest();
	std::cout << std::endl;
	errTest();
}

int
main() {
	theirTests();
	std::cout << std::endl;
	myTests();
}
