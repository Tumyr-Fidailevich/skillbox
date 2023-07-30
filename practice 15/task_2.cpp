#include <iostream>
#include <vector>



int main()
{
    std::vector<int> array = {2, 7, 11, 15};
    int result;
    std::cout << "Input result: ";
    std::cin >> result;
    for (int i = 0; i < array.size(); i++)
    {
        for(int j = i + 1; j < array.size(); j++){
            if(array[i] + array[j] == result){
                std::cout << array[i] << " + " << array[j] << " = " << result << std::endl;
                return 0;
            }
        }
    }
    return 1;
}