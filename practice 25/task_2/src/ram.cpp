#include <fstream>
#include <vector>

void write(std::vector<int> &disk)
{
    std::ofstream ram("buffer.txt");
    if (ram.is_open())
    {
        for (int i = 0; i < disk.size(); i++)
        {
            ram << disk[i] << std::endl;
        }
    }
    ram.close();
}

void read(std::vector<int> &disk)
{
    std::ifstream ram("buffer.txt");
    if (ram.is_open())
    {
        int i = 0;
        while (!ram.eof() && i < disk.size())
        {
            ram >> disk[i] >> std::endl;
            i++;
        }
    }
    ram.close();
}