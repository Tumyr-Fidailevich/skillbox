#include <iostream>
#include <vector>
#include "ram.h"

void compute()
{
    int sum = 0;
    std::vector<int> ram(8, 0);
    read(ram);
    for(int i = 0; i < ram.size(); i++)
    {
        sum += ram[i];
    }
    std::cout << "Sum of numbers in ram: " << sum << std::endl;
}