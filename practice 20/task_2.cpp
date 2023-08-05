#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>

void writePicture(int &width, int &height, std::string &fileName)
{
    std::string path = fileName + ".txt";
    std::ofstream picture(path);
    for(int i = 0; i < height; i++){
        for(int j = 0; j < width; j++){
            picture << std::rand() % 2;
        }
        picture << std::endl;
    }
    picture.close();
}

void readPicture(std::string &absPath)
{
    std::ifstream text(absPath);
    if (text.is_open())
    {
        std::string line;
        while (std::getline(text, line))
        {
            std::cout << line << std::endl;
        }
    }
    text.close();
}

int main()
{
    std::srand(std::time(nullptr));
    int width, height;
    std::cout << "Input width of picture: ";
    std::cin >> width;
    std::cout << "Input height of picture: ";
    std::cin >> height;
    std::string fileName;
    std::cout << "Input filename for picture: ";
    std::cin >> fileName;
    writePicture(width, height, fileName);
    return 0;
}