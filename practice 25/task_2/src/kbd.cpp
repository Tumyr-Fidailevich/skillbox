#include <iostream>
#include <stdexcept>
#include <string>
#include "ram.h"

void input()
{
    std::vector<int> ram(8, 0);
    std::string number;
    std::cout << "Input 8 numbers: ";
    for(int i = 0; i < ram.size(); i++)
    {
        std::cin >> number;
        try
        {
            ram[i] = std::stoi(number);
        }
        catch(const std::invalid_argument e)
        {
            std::cout << "Invalid input" << std::endl;
            break;
        }
    }
    write(ram);
}