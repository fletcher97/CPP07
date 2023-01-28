#if !defined(ARRAY_TPP)
#define ARRAY_TPP

#include <stdexcept>

template<typename T>
class Array {
private:
	T* _arr;
	unsigned int _size;
public:
	Array();
	Array(unsigned int n);
	Array(const Array& other);
	Array<T>& operator=(const Array& other);
	~Array();

	const T& operator[](const unsigned int i) const throw (std::range_error);
	T& operator[](const unsigned int i) throw (std::range_error);

	unsigned int size() const;
	void set(T n);

};

template<typename T>
std::ostream& operator<<(std::ostream& out, const Array<T>& form);

#include "Array.ipp"

#endif // ARRAY_TPP
