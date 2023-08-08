#include <iostream>
#include <cstdlib>

#define FOR()
#define CALL(func, arg1, arg2) \
    {                          \
        func(arg1, arg2);      \
    }
#define FOR_LOOP(variable, count, initialValue) \
    for (int variable = initialValue; variable < count; variable++)

#define CHECK_CARRIAGE(passengers, number) \
    if (passengers > 20) { \
        std::cout << number + 1 << " carriage is full" << std::endl; \
    } else if (passengers < 20) { \
        std::cout << "There are empty seats in " << number + 1 << " carriage" << std::endl; \
    } 

int main()
{
    int train[10];
    std::cout << "Input number of passengers in each carriage: " << std::endl;
    FOR_LOOP(i, 10, 0)
    {
        std::cin >> train[i];
    }
    FOR_LOOP(i, 10, 0)
    {
        CALL(CHECK_CARRIAGE, train[i], i);
    }
    return 0;
}