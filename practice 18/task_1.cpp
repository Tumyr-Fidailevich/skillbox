#include <iostream>
#include <limits>
#include <numeric>
#include <limits>
#include <vector>
#include <sstream>

bool numberValidation(std::string &number)
{
    for (int i = 0; i < number.length(); i++)
    {
        if (number[i] < '0' || number[i] > '9')
        {
            return false;
        }
    }
    return true;
}

void swapvec(std::vector<int> vec, int arr[], int &size)
{
    for (int i = 0; i < size; i++)
    {
        std::swap(vec[i], arr[i]);
    }
    for (int i = 0; i < size; i++)
    {
        std::cout << vec[i] << " ";
    }
    std::cout << std::endl;
    for (int i = 0; i < size; i++)
    {
        std::cout << arr[i] << " ";
    }
}

bool readVector(std::vector<int> &vec, int &size)
{
    std::cin.clear();
    std::string buffer;
    getline(std::cin, buffer);
    std::stringstream buffer_stream(buffer);
    std::string str;
    int i = 0;
    for (int i = 0; i < size; i++)
    {
        if (!(buffer_stream >> str))
        {
            std::cout << "Error in values amount\n";
            return false;
        }
        if (numberValidation(str))
        {
            vec.push_back(std::stoi(str));
        }
        else
        {
            std::cout << "Error in input values\n";
            return false;
        }
    }
    if(buffer_stream >> str){
        std::cout << "Error in values amount\n";
        return false;
    }
    return true;
}

bool readArray(int arr[], int &size)
{
    std::string buffer;
    getline(std::cin, buffer);
    std::stringstream buffer_stream(buffer);
    std::string str;
    for (int i = 0; i < size; i++)
    {
        if (!(buffer_stream >> str))
        {
            std::cout << "Error in values amount\n";
            return false;
        }
        if (numberValidation(str))
        {
            arr[i] = std::stoi(str);
        }
        else
        {
            std::cout << "Error in input values\n";
            return false;
        }
    }
    if(buffer_stream >> str){
        std::cout << "Error in values amount\n";
        return false;
    }
    return true;
}

template <typename T>
void printIterable(const T& iterable, int size) {
    for (int i = 0; i < size; i++) {
        std::cout << iterable[i] << " ";
    }
    std::cout << std::endl;
}

int main()
{
    int size;
    std::cout << "Input size of vector and array: ";
    std::cin >> size;
    std::vector<int> vec;
    int arr[size];
    std::cout << "Input integer values from vector: ";
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    bool isReaded;
    isReaded = readVector(vec, size);
    if(isReaded){
        std::cout << "Input integer values from array: ";
        isReaded = readArray(arr, size);
        if(isReaded){
            swapvec(vec, arr, size);
        }
    }
    return 0;
}