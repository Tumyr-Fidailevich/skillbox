#include <iostream>
#include <fstream>
#include <limits>
#include <numeric>

bool isName(std::string &name)
{
    if (name.length() > 0)
    {
        for (int i = 0; i < name.length(); i++)
        {
            if ((name[i] < 'A' || name[i] > 'z') && name[i] != '-')
            {
                return false;
            }
        }
    }
    else
    {
        return false;
    }
    return true;
}
//5.12.2022
bool isDate(std::string &date)
{
    int curPoint = -1;
    int pos = 0;
    for (int i = 0; i < date.length(); i++)
    {
        int number;
        if (date[i] == '.' || i == date.length() - 1)
        {
            try
            {
                number = std::stoi(date.substr(curPoint + 1, i - curPoint - 1 + i / (date.length() - 1)));
            }
            catch (const std::invalid_argument &e)
            {
                return false;
            }
            curPoint = i;
            pos++;
        }
        if(pos == 0 && curPoint != -1){
            return number > 0 || number < 32;
        }else if(pos == 1){
            return number > 0 || number < 13;
        }
    }
    return true;
}

bool isNumber(std::string &number)
{
    try{
        std::stod(number);
    }
    catch(const std::invalid_argument &e){
        return false;
    }
    return true;
}

int main()
{
    std::ofstream dataBase("C:\\skillbox\\practice 20\\db.txt", std::ios::app);
    std::string name, surname, date, sum;
    std::cout << "Input data: ";
    std::cin >> name >> surname >> date >> sum;
    if (isName(name) && isName(surname) && isDate(date) && isNumber(sum))
    {
        dataBase << name << ' ' << surname << ' ' << date << ' ' << sum << std::endl;
    }
    else
    {
        std::cout << "Invalid data" << std::endl;
    }
    dataBase.close();
    return 0;
}