#include <iostream>
#include <limits>
#include <numeric>
#include <cassert>

float travelTime(float distance, float speed)
{
    return distance / speed;
}

int main()
{

    float distance, speed;
    std::cout << "Input travel distance: ";
    std::cin >> distance;
    std::cout << "Input travel speed: ";
    std::cin >> speed;
    assert(speed > 0);
    std::cout << "Your travel time will be: " << travelTime(distance, speed);
    return 0;
}