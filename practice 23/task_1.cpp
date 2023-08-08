#include <iostream>

#define STR(text) #text
#define MONDAY 1
#define TUESDAY 2
#define WEDNESDAY 3
#define THURSDAY 4
#define FRIDAY 5
#define SATURDAY 6
#define SUNDAY 7

#define DAY_OF_WEEK(day) (day == MONDAY ? STR(MONDAY) : \
                          day == TUESDAY ? STR(TUESDAY) : \
                          day == WEDNESDAY ? STR(WEDNESDAY) : \
                          day == THURSDAY ? STR(THURSDAY) : \
                          day == FRIDAY ? STR(FRIDAY) : \
                          day == SATURDAY ? STR(SATURDAY) : \
                          day == SUNDAY ? STR(SUNDAY) : "Invalid input" )\

int main()
{
    int day;
    std::cout << "Input day: ";
    std::cin >> day;
    std::cout << DAY_OF_WEEK(day);
    return 0;
}