#include <iostream>
#include <limits>
#include <numeric>
#include <vector>

void printBuffer(std::vector<int> &vector, int index)
{
    for (int i = index; i < vector.size(); i++)
    {
        std::cout << vector[i] << " ";
    }
    for(int i = 0; i < index; i++){
        std::cout << vector[i] << " ";
    }
    std::cout << std::endl;
}

int main()
{
    int bufferSize = 5;
    std::vector<int> dataBase(bufferSize);
    int index = 0;
    int number;
    while (true)
    {
        std::cout << "input number: ";
        std::cin >> number;
        while (number != -1){
            dataBase[index++] = number;
            index = index % bufferSize;
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
            printBuffer(dataBase, index);
        }
    }
    return 0;
}