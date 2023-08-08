#include <iostream>
#include <map>
#include <string>
#include <vector>

bool isNumber(std::string &number)
{
    if (number.length() < 8)
        return false;
    for (int i = 0; i < number.length(); i++)
    {
        if ((number[i] < '0' || number[i] > '9') && number[i] != '-')
        {
            return false;
        }
    }
    return true;
}

bool isName(std::string &surname)
{
    if (surname.length() == 0)
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

    std::map<std::string, std::string> phonesToNames;              // ключ - номер, значение - фамилия
    std::map<std::string, std::vector<std::string>> namesToPhones; // ключ - фамилия, значение - вектор из номеров
    while (true)
    {
        std::string phoneNumber, surname, input;
        std::cout << "Input your request: ";
        std::getline(std::cin, input);
        int pos = input.find(' ');
        if (pos == std::string::npos)
        {
            if (isNumber(input))
            {
                phoneNumber = input;
                if (phonesToNames.find(phoneNumber) == phonesToNames.end())
                {
                    std::cout << "There is no this phone number in phone book" << std::endl;
                }
                else
                {
                    std::cout << phonesToNames[phoneNumber] << std::endl;
                }
            }
            else if (isName(input))
            {
                surname = input;
                if (namesToPhones.find(surname) == namesToPhones.end())
                {
                    std::cout << "There is no this surname in phone book" << std::endl;
                }
                else
                {
                    for (int i = 0; i < namesToPhones[surname].size(); i++)
                    {
                        std::cout << namesToPhones[surname][i] << " ";
                    }
                    std::cout << std::endl;
                }
            }
            else
            {
                std::cout << "Invalid input" << std::endl;
                return 1;
            }
        }
        else
        {
            phoneNumber = input.substr(0, pos);
            surname = input.substr(pos + 1, input.length());
            if (isNumber(phoneNumber) && isName(surname))
            {
                if (phonesToNames.find(phoneNumber) == phonesToNames.end())
                {
                    phonesToNames.insert({phoneNumber, surname});
                }
                namesToPhones[surname].push_back(phoneNumber);
            }
            else
            {
                std::cout << "Invalid input" << std::endl;
                return 1;
            }
        }
    }
    return 0;
}