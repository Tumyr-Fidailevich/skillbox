// #include <cmath>
#include <iostream>
// #include <limits>
// #include <numeric>

int main()
{
  int surnamesLength = 10;
  std::string surnames[surnamesLength];
  std::cout << "Input the names of the residents: \n";
  for (int i = 0; i < surnamesLength; i++)
  {
    std::cin >> surnames[i];
  }
  for (int i = 0; i < 3; i++)
  {
    int apartNumber;
    std::cout << "Input apartment number: "
    std::cin >> apartNumber;
    if (apartNumber < 1 || apartNumber > surnamesLength)
    {
      std::cout << "You input wrong apartment number!\n";
      return 1;
    }
    else
    {
      std::cout << surnames[apartNumber - 1] << std::endl;
    }
  }
  return 0;
}