#include <fstream>
#include <iostream>
#include <numeric>
#include <limits>
#include <algorithm>
#include <sstream>

bool isNumber(std::string &number)
{
    for (int i = 0; i < number.length(); i++)
    {
        if (number[i] < '0' || number[i] > '9')
        {
            return false;
        }
    }
    return true;
}

void maxCounter(std::string &absPath)
{
    std::ifstream text(absPath);
    if (text.is_open())
    {
        int sum = 0;
        int maxMoney = 0;
        std::string maxName, maxSurname;
        std::string line;
        while (std::getline(text, line))
        {
            std::string word;
            std::stringstream buffer(line);
            std::string name, surname, money, date;
            buffer >> name >> surname >> money >> date;
            if (line.length() != 0)
            {
                if (isNumber(money) && std::stoi(money) > maxMoney)
                {
                    maxMoney = std::stoi(money);
                    maxName = name;
                    maxSurname = surname;
                }
                sum += std::stoi(money);
            }
        }
        std::cout << maxName + " " + maxSurname + " " << sum << std::endl;
    }
    else
    {
        std::cout << "Invalid path" << std::endl;
    }
    text.close();
}

int main()
{
    std::string path;
    std::cout << "Input your path: ";
    getline(std::cin, path);
    maxCounter(path);
    return 0;
}