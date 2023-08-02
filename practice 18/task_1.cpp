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
    for (int i = 0; i < vec.size(); i++)
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

void readVector(std::vector<int> &vec, int &size)
{
    std::cin.clear();
    std::string buffer;
    getline(std::cin, buffer);
    std::stringstream buffer_stream(buffer);
    std::string str;
    for (int i = 0; i < size; i++)
    {
        if (!(buffer_stream >> str))
        {
            throw std::invalid_argument("Error in values amount\n");
        }
        if (numberValidation(str))
        {
            vec.push_back(std::stoi(str));
        }
        else
        {
            std::cout << "Error in input values\n";
            break;
        }
    }
    if(buffer_stream >> str){
        throw std::invalid_argument("Error in values amount\n");
    }
}

void readArray(int arr[], int &size)
{
    std::string buffer;
    getline(std::cin, buffer);
    std::stringstream buffer_stream(buffer);
    std::string str;
    for (int i = 0; i < size; i++)
    {
        if (!(buffer_stream >> str))
        {
            throw std::invalid_argument("Error in values amount\n");
        }
        if (numberValidation(str))
        {
            arr[i] = std::stoi(str);
        }
        else
        {
            std::cout << "Error in input values\n";
            break;
        }
    }
    if(buffer_stream >> str){
        throw std::invalid_argument("Error in values amount\n");
    }
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
    readVector(vec, size);
    std::cout << "Input integer values from array: ";
    readArray(arr, size);
    swapvec(vec, arr, size);
    return 0;
}