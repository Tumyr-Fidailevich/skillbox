#include <iostream>
#include <vector>
#include "ram.h"

void display()
{
    std::vector<int> ram(8, 0);
    read(ram);
    for(int i = 0; i < ram.size(); i++)
    {
        std::cout << ram[i] << " ";
    }
    std::cout << std::endl;
}