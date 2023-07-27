#include <iostream>
#include <limits>
#include <numeric>
void printArray(float (&arr)[], const int n)
{
    for (int i = 0; i < n; ++i)
        std::cout << arr[i] << " ";
    std::cout << "\n";
}

void heapify(float (&arr)[], const int n, const int i){
  int largest = i;
  int l = 2 * i + 1;
  int r = 2 * i + 2;

  if(l < n && arr[l] < arr[largest]){
    largest = l;
  }
  if(r < n && arr[r] < arr[largest]){
    largest = r;
  }
  if (largest != i){
    std::swap(arr[i], arr[largest]);
    heapify(arr, n, largest);
  }

}

void heapSort(float (&arr)[], const int n)
{

    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    for (int i = n - 1; i > 0; i--) {
 
        std::swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

int main() {
  int n;
  std::cout << "Input dimension of the list: ";
  std::cin >> n;
  float array[n];
  for (int i = 0; i < n; i++){
    float input;
    std::cout << "Input your " << i + 1 << " value: ";
    std::cin >> input;
    if (std::cin.fail() || std::cin.peek() != '\n') {
      std::cerr << "Error\n";
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      return 1;
    }
    array[i] = input;
  }
  heapSort(array, n);
  std::cout << "Sorted array: \n";
  printArray(array, n);
  return 0;
}
