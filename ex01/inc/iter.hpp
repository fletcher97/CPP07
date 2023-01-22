#if !defined(ITER_HPP)
#define ITER_HPP

#include <iostream>

template<typename T>
void iter(T* arr, int size, void (*f)(T& elem)) {
	for (int i = 0; i < size; i++)
		f(arr[i]);
}

template<typename T>
void iter(const T* arr, int size, void (*f)(const T& elem)) {
	for (int i = 0; i < size; i++)
		f(arr[i]);
}

template<typename T>
void print(const T& elem) {
	std::cout << elem << std::endl;
}

template<typename T>
void add1(T& elem) {
	elem += 1;
}

#endif // ITER_HPP
