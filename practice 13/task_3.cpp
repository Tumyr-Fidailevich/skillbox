#include <iostream>
#include <limits>
#include <numeric>
#include <vector>

void printArray(std::vector<int> &vector)
{
    for (int i = 0; i < vector.size(); i++)
    {
        std::cout << vector[i] << " ";
    }
    std::cout << std::endl;
}

void rewriteBuffer(std::vector<int> &vector, int number)
{
    for (int i = 0; i < vector.size(); i++)
    {
        vector[i] = vector[i + 1];
    }
    vector[vector.size() - 1] = number;
}

int main()
{
    std::vector<int> dataBase(5);
    int i = 0;
    while (true)
    {
        int number;
        std::cout << "input number: ";
        std::cin >> number;
        while (number != -1)
        {
            if (i < dataBase.size())
            {
                dataBase[i] = number;
                i++;
            }
            else
            {
                rewriteBuffer(dataBase, number);
            }
            std::cout << "input number: ";
            std::cin >> number;
        }
        if (std::cin.fail() || std::cin.peek() != '\n')
        {
            std::cerr << "Error\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return 1;
        }
        else
        {
            printArray(dataBase);
        }
    }
    return 0;
}