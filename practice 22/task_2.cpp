#include <iostream>
#include <map>
#include <string>
#include <vector>

bool isName(std::string &surname)
{
    if (surname.length() == 0 || surname[0] < 'A' || surname[0] > 'Z')
        return false;
    for (int i = 0; i < surname.length(); i++)
    {
        if ((surname[i] < 'A' || (surname[i] > 'Z' && surname[i] < 'a') || surname[i] > 'z') && surname[i] != '-')
        {
            return false;
        }
    }
    return true;
}

int main()
{

    std::map<int, std::vector<std::string>> posToNames; // ключ - номер, значение - фамилия
    while (true)
    {
        std::string name, input;
        int number = 0;
        std::cout << "Input your request: ";
        std::cin >> input;
        if (input == "Next")
        {
            if (posToNames.empty())
            {
                std::cout << "Queue is empty" << std::endl;
            }
            else
            {
                std::cout << posToNames.begin()->second.back() << std::endl;
                posToNames.begin()->second.pop_back();
                if (posToNames.begin()->second.empty())
                {
                    posToNames.erase(posToNames.begin());
                }
            }
        }
        else if (isName(input))
        {
            name = input;
            number = name[0] - 'A';
            posToNames[number].push_back(name);
        }
        else
        {
            std::cout << "Invalid input" << std::endl;
            return 1;
        }
    }
    return 0;
}