#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>

void readFile()
{
    std::ifstream text;
    text.open("atm.bin", std::ios::binary);
    if (text.is_open())
    {
        const int bufferSize = 64;
        char buffer[bufferSize];
        while (!text.eof())
        {
            text.read(buffer, bufferSize);
            std::streamsize bytesRead = text.gcount();
            for(int i = 0; i < bytesRead; i++){
                std::cout << buffer[i];
            }
        }
    }
    text.close();
}

int getRandomNumber(int min, int max)
{
    return min + std::rand() % (max - min + 1);
}

int* init()
{
    int* bills = new int[1000];
    std::ifstream atm("atm.bin", std::ios::binary);
    if (atm.is_open())
    {
        atm.read((char *)bills, sizeof(int) * 1000);
        atm.close();
    }
    else
    {
        for (int i = 0; i < 1000; i++)
        {
            bills[i] = 0;
        }
    }
    return bills;
}

void addMoney(int* bills)
{
    int arr[] = {1, 2, 5};
    std::ofstream atm("atm.bin", std::ios::binary);
    if (atm.is_open())
    {
        for (int i = 0; i < 1000; i++)
        {
            if (bills[i] == 0)
            {
                int value = arr[getRandomNumber(0, 2)] * 100 * (std::rand() % 2 ? 10 : 1);
                bills[i] = value;
            }
        }
        atm.write((char *)bills, sizeof(int) * 1000);
    }
    atm.close();
}

void getMoney(int *bills, int &userMoney)
{
    std::ofstream atm("atm.bin", std::ios::binary);
    bool opSucces = true;
    if (atm.is_open())
    {
        int bill[] = {5000,
                     2000,
                     1000,
                     500,
                     200,
                     100};
        for (int i = 0; i < 6; i++)
        {
            int billCount = userMoney / bill[i];
            int count = 0;
            std::vector<int> deletedPos;
            for(int j = 0; j < 1000 && count < billCount; j++){
                if(bills[j] == bill[i]){
                    count++;
                    deletedPos.push_back(j);
                }
            }
            if(count != billCount){
                opSucces = false;
            }else{
                for(int j = 0; j < deletedPos.size(); j++){
                    userMoney -= bills[deletedPos[j]];
                    bills[deletedPos[j]] = 0;
                }
            }
        }
        atm.write((char *) bills, sizeof(int) * 1000);
    }else{
        opSucces = false;
    }
    atm.close();
    if (opSucces)
    {
        std::cout << "You have successfully withdrawn money" << std::endl;
    }
    else
    {
        std::cout << "Not enough banknotes at the ATM" << std::endl;
    }
}

int main()
{
    char op;
    // std::srand(std::time(nullptr));
    std::cout << "Input operation: ";
    std::cin >> op;
    std::cin.ignore();
    int* bills = init();
    if (op == '+')
    {
        addMoney(bills);
        std::cout << "Bankomat is full" << std::endl;
    }
    else if (op == '-')
    {
        int userMoney;
        std::cout << "Input the amount you want to withdraw: ";
        std::cin >> userMoney;
        if (userMoney % 100 == 0 && userMoney > 0)
        {
            getMoney(bills, userMoney);
        }
        else
        {
            std::cout << "Invalid sum" << std::endl;
        }
    }
    else if(op == '=')
    {
        readFile();
    }
    else
    {
        std::cout << "Invalid operation" << std::endl;
    }
    delete[] bills;
    return 0;
}