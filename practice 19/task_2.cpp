#include <fstream>
#include <iostream>
#include <numeric>
#include <limits>
#include <algorithm>

// void readFile(std::string &absPath)
// {
//     std::ifstream text(absPath);
//     if (text.is_open())
//     {
//         std::string line;
//         while (std::getline(text, line))
//         {
//             std::cout << line << std::endl;
//         }
//     }
//     text.close();
// }

void readFile(std::string &absPath)
{
    std::ifstream text;
    text.open(absPath, std::ios::binary);
    if (text.is_open())
    {
        const int bufferSize = 64;
        char buffer[bufferSize];
        while (!text.eof())
        {
            text.read(buffer, bufferSize);
            std::streamsize bytesRead = text.gcount();
            for(int i = 0; i < bytesRead; i++){
                std::cout << buffer[i];
            }
        }
    }else{
        std::cout << "Invalid path\n";
    }
    text.close();
}

int main()
{
    std::string path;
    std::cout << "Input your path: ";
    getline(std::cin, path);
    readFile(path);
    return 0;
}