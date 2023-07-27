#include <iostream>
#include <limits>
#include <numeric>

int sum(const int (&arr)[], int size){
    int sum = 0;
    for (int i = 0; i < size; i++){
        sum += arr[i];
    }
    return sum;
}


int findRepeated(const int (&arr)[], int min, int size){
    int initialArray[size - 1];
    for (int i = 0; i < size - 1; i++){
        initialArray[i] = min + i;
    }
    return sum(arr, size) - sum(initialArray, size - 1);
}




int main() {
  while (true) {
    int n, min;
    std::cout << "Input dimension of the array: ";
    std::cin >> n;
    int numbers[n];
    std::cout << "Input min value in the array: ";
    std::cin >> min;
    std::cout << "Input values in this array: \n";
    for (int i = 0; i < n; i++){
      int number;
      std::cin >> number;
      numbers[i] = number;
    }
    if (std::cin.fail() || std::cin.peek() != '\n') {
      std::cerr << "Error\n";
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      return 1;
    } else {
      std::cout << "Repeated number in the input array is: " << findRepeated(numbers, min, n);
      return 0;
    }
  }
}