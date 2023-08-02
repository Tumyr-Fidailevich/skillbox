#include <iostream>
#include <string>
#include <algorithm>

int combCount(int stepsNumber, int jumpDist = 3, int curStep = 0)
{
    if (curStep == stepsNumber)
    {
        return 1;
    }
    else if (curStep > stepsNumber)
    {
        return 0;
    }
    int ways = 0;
    for(int jump = 1; jump <= jumpDist; jump++){
        ways+= combCount(stepsNumber, jumpDist, curStep + jump);
    }
    return ways;
    
}

bool numberValidation(std::string &number)
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

int main()
{
    std::string numbers;
    std::cout << "Input numbers: ";
    std::string stepsNumber, jumpDist;
    std::cin >> stepsNumber >> jumpDist;
    stepsNumber.erase(std::remove(stepsNumber.begin(), stepsNumber.end(), ','), stepsNumber.end());
    if (numberValidation(stepsNumber) && numberValidation(jumpDist))
    {
        std::cout << "There are " << combCount(std::stoi(stepsNumber), std::stoi(jumpDist)) << " combinations\n";
    }
    else
    {
        std::cout << "Wrong input data\n";
    }
    return 0;
}