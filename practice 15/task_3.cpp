#include <iostream>
#include <vector>

void printArray(std::vector<int> &array)
{
    for (int i = 0; i < array.size(); ++i)
        std::cout << array[i] << " ";
    std::cout << "\n";
}

void heapify(std::vector<int> &array, const int n, const int i)
{
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < n && array[l] > array[largest])
    {
        largest = l;
    }
    if (r < n && array[r] > array[largest])
    {
        largest = r;
    }
    if (largest != i)
    {
        std::swap(array[i], array[largest]);
        heapify(array, n, largest);
    }
}

void heapSort(std::vector<int> &array)
{

    for (int i = array.size() / 2 - 1; i >= 0; i--)
        heapify(array, array.size(), i);

    for (int i = array.size() - 1; i > 0; i--)
    {

        std::swap(array[0], array[i]);
        heapify(array, i, 0);
    }
}

int main()
{
    std::vector<int> arr = {};
    int input;
    std::cout << "Input: ";
    std::cin >> input;
    while(input != -2){
        if(input == -1 && arr.size() >= 5 ){
            std::cout << "Output: " << arr[4] << std::endl;
        }else if(input != -1){
            arr.push_back(input);
            heapSort(arr);
        }else{
            std::cout << "Not enough elements in the array!\n;";
        }
        std::cout << "Input: ";
        std::cin >> input;
    }
    std::cout <<"End.\n";
    return 0;
}