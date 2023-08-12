#include <iostream>
#include <string>
#include "cpu.h"
#include "disk.h"
#include "gpu.h"
#include "kbd.h"
#include "ram.h"

int main()
{
    std::string in;
    std::cout << "Input command: ";
    std::cin >> in;
    if(in == "input")
    {
        input();
    }
    else if(in == "sum")
    {
        compute();
    }
    else if(in == "save")
    {
        save();
    }
    else if(in == "load")
    {
        load();
    }
    else if(in == "display")
    {   
        display();
    }
    else if(in == "exit")
    {
        return 0;
    }
    else 
    {
        std::cout << "Invalid input" << std::endl;
        return 1;
    }
    return 0;
}