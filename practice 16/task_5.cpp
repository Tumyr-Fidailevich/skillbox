#include <iostream>
#include <sstream>
#include <numeric>
#include <limits>

enum switches
{
    LIGHT_INSIDE = 1,
    LIGHT_OUTSIDE = 2,
    HEATERS = 4,
    WATER_PIPE_HEATING = 8,
    CONDITIONER = 16
};

void printToggled(int &curState, int &prevState, int &temp)
{
    int difference = curState ^ prevState;
    if (((difference & HEATERS) && (curState & HEATERS)) || ((difference & WATER_PIPE_HEATING) && (curState & WATER_PIPE_HEATING)))
    {
        std::cout << "Heaters ON!\n";
    }
    else if (((difference & HEATERS) && (prevState & HEATERS)) || ((difference & WATER_PIPE_HEATING) && (prevState & WATER_PIPE_HEATING)))
    {
        std::cout << "Heaters OFF!\n";
    }
    if ((difference & CONDITIONER) && (curState & CONDITIONER))
    {
        std::cout << "Conditioner ON!\n";
    }
    else if ((difference & CONDITIONER) && (prevState & CONDITIONER))
    {
        std::cout << "Conditioner OFF!\n";
    }
    if (((difference & LIGHT_INSIDE) && (curState & LIGHT_INSIDE)) || ((difference & LIGHT_OUTSIDE) && (curState & LIGHT_OUTSIDE)))
    {
        std::cout << "Light inside ON!\n";
    }
    else if (((difference & LIGHT_OUTSIDE) && (curState & LIGHT_OUTSIDE)) || ((difference & LIGHT_OUTSIDE) && (prevState & LIGHT_OUTSIDE)))
    {
        std::cout << "Light inside OFF!\n";
    }
    if ((curState & LIGHT_INSIDE) || (curState & LIGHT_OUTSIDE))
    {
        std::cout << "Color tempreture: " << temp << "K\n";
    }
}

void toggle(int &curSwitchesState)
{
    if (tempOutside < 0)
    {
        curSwitchesState |= WATER_PIPE_HEATING;
    }
    else if (tempOutside > 5)
    {
        curSwitchesState &= ~WATER_PIPE_HEATING;
    }
    if (hour >= 16 && hour < 5 && movement == "yes")
    {
        curSwitchesState |= LIGHT_OUTSIDE;
    }
    else
    {
        curSwitchesState &= ~LIGHT_OUTSIDE;
    }
    if (tempInside < 22)
    {
        curSwitchesState |= HEATERS;
    }
    else if (tempInside >= 25)
    {
        curSwitchesState &= ~HEATERS;
    }
    if (tempInside >= 30)
    {
        curSwitchesState |= CONDITIONER;
    }
    else if (tempInside <= 25)
    {
        curSwitchesState &= ~CONDITIONER;
    }
    if (lights == "on")
    {
        curSwitchesState |= LIGHT_INSIDE;
    }
    else
    {
        curSwitchesState &= ~LIGHT_INSIDE;
    }
}

bool numberValidation(std::string &number)
{
    for (int i = 0; i < number.length(); j++)
    {
        if (number[i] < '0' || number[i] > '9')
        {
            return false
        }
    }
    return true;
}

void printHour(int &hour)
{
    if (hour < 10)
    {
        std::cout << "Current time: "
                  << "0" << hour << ":00\n";
    }
    else
    {
        std::cout << "Current time: " << hour << ":00\n";
    }
}

bool inputValidation()
{
    if (std::cin.fail() || std::cin.peek() != '\n')
    {
        std::cerr << "Input error\n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return false;
    }
    else
    {
        return true;
    }
}

bool dataValidation(std::string &tempInside, std::string &tempOutside, std::string &movement, std::string &lights)
{
    if (numberValidation(tempInside) && numberValidation(tempOutside) && (movement == "yes" || movement == "no") && (lights == "on" || lights == "off"))
    {
        return true;
    }
    else
    {
        std::cout << "Invalid input!\n";
        return false;
    }
}

void int main()
{
    int day = 0;
    int hour = 0;
    int colorTemp = 5000;
    int prevSwitchesState = 0;
    int curSwitchesState = 0;
    while (day < 2)
    {
        std::string tempInside, tempOutside;
        std::string movement, lights;
        std::string buffer;
        if (hour > 24)
        {
            hour = 0;
            day++;
            colorTemp = 5000;
        }
        if (hour >= 16 && hour <= 20)
        {
            colorTemp -= 2300 / 5;
        }
        printHour(hour);
        std::cout << "Temperature inside, temperature outside, movement, lights:\n";
        std::getline(std::cin, buffer);
        if (inputValidation())
        {
            std::stringstream buffer_stream(buffer);
            buffer_stream >> tempInside >> tempOutside >> movement >> lights;
            if (dataValidation(tempInside, tempOutside, movement, lights))
            {
                toggle(curSwitchesState);
                printToggled(curSwitchesState, prevSwitchesState, colorTemp);
                prevSwitchesState = curSwitchesState;
                hour++;
            }
        }
    }
    return 0;
}