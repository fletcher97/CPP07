#if !defined(WHATEVER_HPP)
#define WHATEVER_HPP

template<typename T>
void swap(T& a, T& b) {
	T tmp = a;
	a = b;
	b = tmp;
}

template<typename T>
const T& min(const T& a, const T& b) {
	return (a < b ? a : b);
}

template<typename T>
const T& max(const T& a, const T& b) {
	return (a > b ? a : b);
}

template<typename T>
void printPair(const T& a, const T& b) {
	std::cout << "First: " << a << ", Second: " << b << std::endl;
}

template<typename T>
void printMax(const T& a, const T& b) {
	std::cout << "Max between " << a << " and " << b << ": " << max<T>(a, b) << std::endl;
}

template<typename T>
void printMin(const T& a, const T& b) {
	std::cout << "Min between " << a << " and " << b << ": " << min<T>(a, b) << std::endl;
}


#endif // WHATEVER_HPP
