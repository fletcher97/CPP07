#include <iostream>

#include "data.hpp"

std::ostream&
operator<<(std::ostream& out, const data_t& data) {
	out << "{i: " << data.i << ", c: " << data.c << "}";
	return out;
}
