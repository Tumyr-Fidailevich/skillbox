#include <iostream>
#include <limits>
#include <numeric>

void printArray(int array[2][6]){
  for(int i = 0; i < 2; i++){
    for(int j = 0; j < 6; j++){
      std::cout << array[i][j] << " ";
    }
    std::cout << std::endl;
  }
}

int main()
{
  
  while (true)
  {
    bool table[2][6] = {{true, false, false, false, false, false},
                {true, false, false, false, false, false}};
    int cutlery[2][6];
    int dishes[2][6];
    int chairs[2][6];
    for (int i = 0; i < 2; i++){
      for (int j = 0; j < 6; j++){
        cutlery[i][j] = 3;
        dishes[i][j] = 2;
        chairs[i][j] = 1;
        if(table[i][j]){
          cutlery[i][j]++;
          dishes[i][j]++;
        }
      }
    }
    std::cout << "Cutlery: \n";
    printArray(cutlery);
    std::cout << "Dishes: \n";
    printArray(dishes);
    std::cout << "Chairs: \n";
    printArray(chairs);
    std::cout << "-----------------------\n";
    chairs[0][4]++;
    printArray(chairs);
    std::cout << "-----------------------\n";
    cutlery[1][2]--;
    printArray(cutlery);
    cutlery[1][2]++;
    printArray(cutlery);
    cutlery[1][0]--;
    printArray(cutlery);
    std::cout << "-----------------------\n";
    dishes[1][0]--;
    printArray(dishes);
    // if (std::cin.fail() || std::cin.peek() != '\n')
    if(false)
    {
      std::cerr << "Error\n";
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      return 1;
    }
    else
    {
      return 0;
    }
  }
}