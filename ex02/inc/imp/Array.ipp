#if !defined(ARRAY_IPP)
#define ARRAY_IPP

#include "Array.tpp"

template<typename T>
Array<T>::Array() {
	this->_size = 0;
}

template<typename T>
Array<T>::Array(unsigned int n) {
	this->_arr = new T[n]();
	this->_size = n;
}

template<typename T>
Array<T>::Array(const Array& other) {
	if (other._size != 0)
		this->_arr = new T[other._size]();
	this->_size = other._size;
	for (unsigned int i = 0; i < this->_size; i++)
		this->_arr[i] = other._arr[i];
}

template<typename T>
Array<T>&
Array<T>::operator=(const Array<T>& other) {
	if (*this != other) {
		if (this->_size != other._size) {
			if (this->_size != 0)
				delete[] this->_arr;
			this->_size = other._size;
			if (other._size != 0)
				this->_arr = new T[other._size]();
		}
		for (unsigned int i = 0; i < this->_size; i++)
			this->_arr[i] = other._arr[i];
	}
	return *this;
}


template<typename T>
Array<T>::~Array() {
	if (this->_size != 0)
		delete[] this->_arr;
}

template<typename T>
const T&
Array<T>::operator[](const unsigned int i) const throw (std::range_error) {
	if (i >= this->_size)
		throw std::range_error("Index out of bounds");
	return this->_arr[i];
}

template<typename T>
T&
Array<T>::operator[](const unsigned int i) throw (std::range_error) {
	if (i >= this->_size)
		throw std::range_error("Index out of bounds");
	return this->_arr[i];
}

template<typename T>
unsigned int
Array<T>::size() const {
	return this->_size;
}

template<typename T>
void
Array<T>::set(T n) {
	for (unsigned int i = 0; i < this->_size; i++)
		this->_arr[i] = n;
}

template<typename T>
std::ostream&
operator<<(std::ostream& out, const Array<T>& array) {
	if (array.size() == 0) {
		out << "[]";
		return out;
	}
	out << "[" << array[0];
	for (unsigned int i = 1; i < array.size(); i++)
		out << ", " << array[i];
	out << "]";
	return out;
}

#endif // ARRAY_IPP
