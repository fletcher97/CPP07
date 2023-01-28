#if !defined(DATA_HPP)
#define DATA_HPP

typedef struct data
{
	int i;
	char c;
} data_t;

std::ostream& operator<<(std::ostream& out, const data_t& data);

#endif // DATA_HPP
