#include <iostream>
#include <fstream>
#include <cstdlib>
#include <vector>

struct Data
{
    std::string name = "unknown";
    std::string surname = "unknown";
    std::string date = "5.8.2023";
    int payout = 0;
};

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
bool isDate(std::string &date)
{
    int pos = 0;
    int dot1 = date.find('.');
    int dot2 = date.find('.', dot1 + 1);

    if (dot1 == std::string::npos || dot2 == std::string::npos || dot1 == 0 || dot2 == date.length() - 1)
    {
        return false;
    }
    int day = std::stoi(date.substr(0, dot1));
    int month = std::stoi(date.substr(dot1 + 1, dot2 - dot1 - 1));
    int year = std::stoi(date.substr(dot2 + 1));

    if (year > 0)
    {
        if (month == 2)
        {
            if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
            {
                return day > 0 && day < 30;
            }
            else
            {
                return day > 0 && day < 29;
            }
        }
        else if (month == 8)
        {
            return day > 0 && day < 32;
        }
        else if (month > 0 && month < 8)
        {
            return (month % 2 == 0 && day > 0 && day < 31) || (month % 2 != 0 && day > 0 && day < 32);
        }
        else if (month > 7 && month < 13)
        {
            return (month % 2 != 0 && day > 0 && day < 31) || (month % 2 == 0 && day > 0 && day < 32);
        }
        else
        {
            return false;
        }
    }
    else
    {
        return false;
    }
}
bool isNumber(std::string &number)
{
    try
    {
        std::stod(number);
    }
    catch (const std::invalid_argument &e)
    {
        return false;
    }
    return true;
}

void read_person(std::ifstream &dataBase, Data &person)
{
    int name_len = 0, surname_len = 0, date_len = 0;
    dataBase.read((char *)&name_len, sizeof(name_len));
    person.name.resize(name_len);
    dataBase.read((char *)person.name.c_str(), name_len);

    dataBase.read((char *)&surname_len, sizeof(surname_len));
    person.surname.resize(surname_len);
    dataBase.read((char *)person.surname.c_str(), surname_len);

    dataBase.read((char *)&date_len, sizeof(date_len));
    person.date.resize(date_len);
    dataBase.read((char *)person.date.c_str(), date_len);

    dataBase.read((char *)&person.payout, sizeof(person.payout));
}

void write_person(std::ofstream &dataBase, Data &person)
{
    int name_len = person.name.length();
    int surname_len = person.surname.length();
    int date_len = person.date.length();
    dataBase.write((char *)&name_len, sizeof(name_len));
    dataBase.write(person.name.c_str(), name_len);
    dataBase.write((char *)&surname_len, sizeof(surname_len));
    dataBase.write(person.surname.c_str(), surname_len);
    dataBase.write((char *)&date_len, sizeof(date_len));
    dataBase.write(person.date.c_str(), date_len);
    dataBase.write((char *)&person.payout, sizeof(person.payout));
}
int main()
{
    std::string operation;
    std::cout << "Input operation (list, add): ";
    std::cin >> operation;
    if (operation == "list")
    {
        std::ifstream dataBase("db.bin", std::ios::binary);
        Data person;
        if (dataBase.is_open())
        {
            while (!dataBase.eof())
            {
                read_person(dataBase, person);
                std::cout << person.name << " " << person.surname << " " << person.date << " " << person.payout << std::endl;
            }
        }
        else
        {
            std::cout << "Data base does not exist yet" << std::endl;
        }
        dataBase.close();
    }
    else if (operation == "add")
    {
        std::ofstream dataBase("db.bin", std::ios::binary | std::ios::app);
        if (dataBase.is_open())
        {
            Data person;
            std::string name, surname, date, payout;
            std::cout << "Input data: ";
            std::cin >> name >> surname >> date >> payout;
            if (isName(name) && isName(surname) && isDate(date) && isNumber(payout))
            {
                person.name = name;
                person.surname = surname;
                person.date = date;
                person.payout = std::stoi(payout);
                write_person(dataBase, person);
            }
            else
            {
                std::cout << "Invalid data" << std::endl;
            }
        }
        dataBase.close();
    }
    else
    {
        std::cout << "Unknown operation" << std::endl;
    }
    return 0;
}