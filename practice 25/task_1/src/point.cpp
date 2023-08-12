#include <iostream>
#include <string>
#include <stdexcept>
#include "point.h"

Point initPoint()
{
    Point point;
    std::string x, y;
    std::cout << "Input coordindates: ";
    try
    {
        std::cin >> x >> y;
        point.x = std::stod(x);
        point.y = std::stod(y);
    }
    catch(std::invalid_argument e)
    {
        std::cout << "Invalid arguments" << std::endl;
    }
    return point;
}

void show(Point &point)
{
    std::cout << "(" << point.x << "," << point.y <<")";
}

bool isEqual(Point &start, Point &end)
{
    return start.x == end.x && start.y == end.y;
}