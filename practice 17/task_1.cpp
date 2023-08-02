#include <iostream>
#include <limits>
#include <numeric>

void mySwap(int* a, int* b)
{
    *a = *a + *b;
    *b = *a - *b;
    *a = *a - *b;
}

int main()
{

    int a, b;
    std::cout << "Input 2 integer numbers: ";
    std::cin >> a >> b;
    if (std::cin.fail() || std::cin.peek() != '\n')
    {
        std::cerr << "Error\n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return 1;
    }
    else
    {
        mySwap(&a, &b);
        std::cout << a << " " << b << std::endl;
        return 0;
    }
}