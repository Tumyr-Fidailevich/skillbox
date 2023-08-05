#include <iostream>
#include <fstream>

void appendFish(std::string &fish)
{
    int amount = 0;
    std::ifstream river("river.txt");
    if (river.is_open())
    {
        std::string line;
        std::ofstream basket("basket.txt", std::ios::app);
        while (std::getline(river, line))
        {
            if (fish == line)
            {
                basket << fish << std::endl;
                amount++;
            }
        }
        basket.close();
    }
    river.close();
    std::cout << amount << " fish caught" << std::endl;
}

int main()
{
    std::string fish;
    std::cout << "Input fish name: ";
    std::cin >> fish;
    appendFish(fish);
    return 0;
}