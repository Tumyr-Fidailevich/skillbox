#include <iostream>
#include <string>
#include "point.h"
#include "surgery.h"


int main()
{
    std::string input;
    Surgery surgery;
    Point start;
    Point end;
    while(surgery.status != ended)
    {
        std::cout << "Input operation: ";
        std::cin >> input;
        if(input == "scalpel")
        {
            if(surgery.status == not_started)
            {
                surgery.status = started;
                start = initPoint();
                end = initPoint();
                surgery.start = start;
                surgery.end = end;
            }
            scalpel(start, end);
        }
        else if(input == "hemostat")
        {
            start = initPoint();
            hemostat(start);
        }
        else if(input == "tweezers")
        {
            start = initPoint();
            tweezers(start);
        }
        else if(input == "suture")
        {
            start = initPoint();
            end = initPoint();
            if(isEqual(surgery.start, start) && isEqual(surgery.end, end))
            {
                std::cout << "Surgery completed" << std::endl;
                surgery.status = ended;
            }
            else
            {
                suture(start, end);
            }
        }
        else
        {
            std::cout << "Invalid input" << std::endl;
            return 1;
        }
    }
    return 0;
}