#pragma once
#include "point.h"

enum surgeryStatus
{
    not_started,
    started,
    ended
};

struct Surgery
{
    Point start;
    Point end;
    int status = not_started;
};

void scalpel(Point &start, Point &end);

void hemostat(Point &point);

void tweezers(Point &point);

void suture(Point &start, Point &end);