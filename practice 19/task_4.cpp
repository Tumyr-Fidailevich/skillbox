#include <fstream>
#include <iostream>

bool isPNG(std::string &absPath)
{
    std::ifstream text;
    text.open(absPath, std::ios::binary);
    bool is = false;
    if (text.is_open())
    {
        char line[4];
        text.read(line, sizeof(line));
        if(absPath.length() >= 4 && line[0] == -119 && line[1] == 'P' && line[2] == 'N' && line[3] == 'G' && absPath.substr(absPath.length() - 4, 4) == ".png"){
            is = true;
        }
    }
    else
    {
        std::cout << "Invalid path" << std::endl;
    }
    text.close();
    return is;
}

int main()
{
    std::string path;
    std::cout << "Input your path: ";
    getline(std::cin, path);
    if (isPNG(path))
    {
        std::cout << "This is png file" << std::endl;
    }
    else
    {
        std::cout << "This is not png file" << std::endl;
    }
    return 0;
}