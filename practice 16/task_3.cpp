#include <iostream>
#include <sstream>
#include <cmath>

int main()
{
    std::string buffer;
    std::cout << "Input your equation: ";
    std::cin >> buffer;
    double firstNumber, secondNumber;
    char operation;
    std::stringstream buffer_stream(buffer);
    buffer_stream >> firstNumber >> operation >> secondNumber;
    if(operation == '*'){
        std::cout << "Result: " << firstNumber * secondNumber;
    }else if(operation == '+'){
        std::cout << "Result: " << firstNumber + secondNumber;
    }else if(operation == '-'){
        std::cout << "Result: " << firstNumber - secondNumber;
    }else if(operation == '/'){
        std::cout << "Result: " << firstNumber / secondNumber;
    }else if(operation == '^'){
        std::cout << "Result: " << std::pow(firstNumber, secondNumber);
    }
    return 0;
}