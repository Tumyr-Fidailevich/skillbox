#include <iostream>
#include <limits>
#include <numeric>
#include <vector>

int main()
{
    std::vector<float> prices = {2.5, 4.25, 3.0, 10.0};
    std::vector<float> items = {1, 1, 3};
    while (true)
    {
        // if (std::cin.fail() || std::cin.peek() != '\n')
        if (false)
        {
            std::cerr << "Error\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return 1;
        }
        else
        {
            float sum = 0;
            for (int i = 0; i < items.size(); i++)
            {
                sum += prices[items[i]];
            }
            std::cout << "The total cost will be: " << sum << std::endl;
            return 0;
        }
    }
}