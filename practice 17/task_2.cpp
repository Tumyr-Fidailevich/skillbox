#include <iostream>

void reverse(int arr[], const int &size)
{
    for(int i = 0; i < size / 2; i++){
        std::swap(*(arr + i), *(arr + size - i - 1));
    }
}

void printArray(int arr[], const int &size){
    for (int i = 0; i < size; i++)
    {
        std::cout << *(arr + i) << " ";
    }
    std::cout << std::endl;
}

int main()
{
    int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int size = sizeof(a) / sizeof(a[0]);
    printArray(a, size);
    reverse(a, size);
    printArray(a, size);
    return 0;
}