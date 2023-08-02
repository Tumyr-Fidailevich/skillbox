#include <iostream>
#include <limits>
#include <numeric>

bool numberValidation(std::string &number)
{
    for (int i = 0; i < number.length(); i++)
    {
        if (number[i] < '0' || number[i] > '9')
        {
            std::cout << "Input error!\n";
            return false;
        }
    }
    return true;
}

bool inputValidation()
{
    if (std::cin.fail() || std::cin.peek() != '\n')
    {
        std::cerr << "Input error\n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return false;
    }
    else
    {
        return true;
    }
}

int main()
{
    std::string intPart, fractionalPart;
    double result;
    std::cout << "Input the integer part of number: ";
    std::cin >> intPart;
    std::cout << "Input fractional part of a number: ";
    std::cin >> fractionalPart;
    if(numberValidation(intPart) && numberValidation(fractionalPart) && inputValidation()){
        result = std::stod(intPart + "." + fractionalPart);
        std::cout << result;
    }
    return 0;
}