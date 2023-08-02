#include <iostream>
#include <sstream>
#include <cmath>
#include <limits>
#include <numeric>

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
    std::string buffer;
    std::cout << "Input your equation: ";
    std::cin >> buffer;
    if (inputValidation())
    {
        double firstNumber, secondNumber;
        char operation;
        std::stringstream buffer_stream(buffer);
        buffer_stream >> firstNumber >> operation >> secondNumber;
        if (operation == '*')
        {
            std::cout << "Result: " << firstNumber * secondNumber;
        }
        else if (operation == '+')
        {
            std::cout << "Result: " << firstNumber + secondNumber;
        }
        else if (operation == '-')
        {
            std::cout << "Result: " << firstNumber - secondNumber;
        }
        else if (operation == '/')
        {
            std::cout << "Result: " << firstNumber / secondNumber;
        }
        else if (operation == '^')
        {
            std::cout << "Result: " << std::pow(firstNumber, secondNumber);
        }
    }

    return 0;
}