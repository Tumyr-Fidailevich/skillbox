#pragma once

struct Point
{
    double x = 0;
    double y = 0;
};

Point initPoint();

void show(Point &point);

bool isEqual(Point &start, Point &end);