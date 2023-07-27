#include <cmath>
#include <iostream>
#include <limits>
#include <numeric>

int main() {
  while (true) {
    if (std::cin.fail() || std::cin.peek() != '\n') {
      std::cerr << "Error\n";
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      return 1;
    } else {
      // Ваш код здесь
      return 0;
    }
  }
}