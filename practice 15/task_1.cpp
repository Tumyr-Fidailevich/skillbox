#include <iostream>
#include <vector>

int main()
{
    std::vector<int> array =  {-2,1,-3,4,-1,2,1,-5,4};
    int sum = 0, minSum = 0, maxIndex = 0, minIndex = 0, minPosition = -1, curElement = 0;
    for (int i = 0; i < array.size(); i++){
        sum += array[i];
        int curSum = sum - minSum;
        if(curSum > curElement){
            maxIndex = i;
            curElement = curSum;
            minIndex = minPosition + 1;
        }
        if(curSum < 0){
            minSum = sum;
            minPosition = i;
        }
    }

    std::cout << "i: " << minIndex << std::endl;
    std::cout << "j: " << maxIndex << std::endl;
}