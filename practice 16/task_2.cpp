#include <iostream>

int main()
{
    int intPart, fractionalPart;
    std::string result;
    std::cout << "Input the integer part of number: ";
    std::cin >> intPart;
    std::cout << "Input fractional part of a number: ";
    std::cin >> fractionalPart;
    result = std::to_string(intPart) + "." + std::to_string(fractionalPart);
    std::cout << result;
}