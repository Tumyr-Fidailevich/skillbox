#include <iostream>
#include <ctime>
#include <iomanip>
#include <chrono>
#include <thread>

int main()
{
    
    std::cout << "Input time: ";
    // only for min and sec
    std::tm timerTM = {};
    std::cin >> std::get_time(&timerTM, "%M/%S");

    std::time_t curTime = std::time(nullptr);
    std::tm targetTimeTM = *std::localtime(&curTime);

    targetTimeTM.tm_min += timerTM.tm_min;
    targetTimeTM.tm_sec += timerTM.tm_sec;

    std::time_t targetTime = std::mktime(&targetTimeTM);
    while(targetTime > std::time(nullptr))
    {
        std::time_t remainingTime = targetTime - std::time(nullptr);
        std::tm remainingTimeTM = *std::localtime(&remainingTime);
        std::cout << remainingTimeTM.tm_min << " minutes " << remainingTimeTM.tm_sec << " seconds left" << std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(1));   
    }
    std::cout << "DING! DING! DING!" << std::endl;
    return 0;
}