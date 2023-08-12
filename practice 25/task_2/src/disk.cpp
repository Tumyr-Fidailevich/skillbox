#include <fstream>
#include <vector>
#include "ram.h"

void save()
{
    std::vector<int> ram(8, 0);
    read(ram);
    std::ofstream disk("data.txt");
    if (disk.is_open())
    {
        for (int i = 0; i < ram.size(); i++)
        {
            disk << ram[i] << std::endl;
        }
    }
    disk.close();
}

void load()
{
    std::vector<int> ram(8, 0);
    std::ifstream disk("data.txt");
    if(disk.is_open())
    {
        int i = 0;
        while(!disk.eof() && i < ram.size())
        {
            disk >> ram[i] >> std::endl;
            i++;
        }
    }
    disk.close();
    write(ram);
}