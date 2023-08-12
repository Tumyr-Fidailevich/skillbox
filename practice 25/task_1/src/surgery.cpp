#include <iostream>
#include "point.h"
#include "surgery.h"

void scalpel(Point &start, Point &end)
{
    std::cout << "A cut is made between a point ";
    show(start);
    std::cout << " and ";
    show(end);
    std::cout << std::endl;
}

void hemostat(Point &point)
{
    std::cout << "Clamp in point ";
    show(point);
    std::cout << std::endl;
}

void tweezers(Point &point)
{
    std::cout << "Tweezers in point ";
    show(point);
    std::cout << std::endl;
}

void suture(Point &start, Point &end)
{
    std::cout << "Suture is made between a point ";
    show(start);
    std::cout << " and ";
    show(end);
    std::cout << std::endl;
}
