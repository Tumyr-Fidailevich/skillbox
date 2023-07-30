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

    if (l < n && std::abs(array[l]) > std::abs(array[largest]))
    {
        largest = l;
    }
    if (r < n && std::abs(array[r]) > std::abs(array[largest]))
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
    std::vector<int> arr = {-100, -50, -5, 1, 10, 15};
    heapSort(arr);
    printArray(arr);
    return 0;
}