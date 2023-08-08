#include <iostream>

#define WINTER 1
#define SPRING 2
#define SUMMER 3
#define AUTUMN 4

int main()
{
    #define SEASON SPRING
    #if SEASON == WINTER
        std::cout << "Winter" << std::endl; 
    #elif SEASON == SPRING
        std::cout << "Spring" << std::endl; 
    #elif SEASON == SUMMER
        std::cout << "Summer" << std::endl; 
    #elif SEASON == AUTUMN
        std::cout << "Autumn" << std::endl;
    #endif
    return 0;
}