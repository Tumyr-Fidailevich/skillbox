#include <iostream>
#include <limits>
#include <numeric>
#include <vector>

void printArray(std::vector<int> &vector)
{
  for (int i = 0; i < vector.size(); i++)
  {
    std::cout << vector[i] << " ";
  }
  std::cout << std::endl;
}

void removeByValue(std::vector<int> &vector, int &value)
{
  int i = 0;
  while (i < vector.size())
  {
    if (vector[i] == value)
    {
      vector.erase(vector.begin() + i);
    }
    else
    {
      i++;
    }
  }
}

int main()
{
  int size;
  std::cout << "Input vector size: ";
  std::cin >> size;
  std::vector<int> array(size);
  std::cout << "Input numbers: ";
  for (int i = 0; i < array.size(); i++)
  {
    int number;
    std::cin >> number;
    array[i] = number;
  }
  while (true)
  {
    if (std::cin.fail() || std::cin.peek() != '\n')
    {
      std::cerr << "Error\n";
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      return 1;
    }
    else
    {
      int deleteNumber;
      std::cout << "Input number to delete: ";
      std::cin >> deleteNumber;
      removeByValue(array, deleteNumber);
      printArray(array);
      return 0;
    }
  }
}