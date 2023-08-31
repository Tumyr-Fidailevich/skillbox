#include <iostream>

class ZeroDivision : std::exception
{
public:
	const char* what() const noexcept override
	{
		return "Zero division error";
	}
};


template <typename T>
void fillArray(T array[], const int &size)
{
	for(int i = 0; i < size; i++)
	{
		std::cout << "Input value: ";
		std::cin >> array[i];
	}
}
template <typename T>
T avg(T array[], const int &size)
{
	T sum = 0;
	if(size == 0) throw ZeroDivision();
	for(int i = 0; i < size; i++)
	{
		sum += array[i];
	}
	return sum / size;
}
int main()
{
	int size;
	std::cout << "Input size: ";
	std::cin >> size;
	if(size < 1)
	{
		std::cout << "Invalid array size" << std::endl;
		return 1;
	}
	float array[size];
	fillArray(array, size);
	try
	{
		std::cout << "Avg: " << avg(array, size) << std::endl;
	}catch(const ZeroDivision &e)
	{
		std::cout << e.what() << std::endl;
	}
	return 0;
}
