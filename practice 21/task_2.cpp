#include <iostream>
#include <fstream>
#include <cstdlib>
#include <vector>

int getRandomNumber(int min, int max)
{
    return min + std::rand() % (max - min + 1);
}

enum room_type
{
    bedroom,
    kitchen,
    bathroom,
    children,
    living
};

enum building_type
{
    garage,
    barn,
    vaporarium,
    house
};

struct Room
{
    int type = 0;
    int area = 0;
};

struct Floor
{
    int celling_height = 0;
    std::vector<Room> rooms;
};

struct Building
{
    int type = 0;
    int area = 0;
    std::vector<Floor> floors;
    int stove = 0;
};

struct Plot
{
    int number = 0;
    std::vector<Building> buildings;
};

int main()
{
    return 0;
}