#include <iostream>
#include <limits>
#include <numeric>

bool numberValidation(std::string &number){
    for(int i = 0; i < number.length(); i++){
        if(*(number + i) < '0' || *(number + i) > '9'){
            return false;
        }
    }
    return true;
}

void mySwap(int* a, int* b)
{
    *a = *a + *b;
    *b = *a - *b;
    *a = *a - *b;
}

int main()
{

    std::string a, b;
    std::cout << "Input 2 integer numbers: ";
    std::cin >> a >> b;
    if (std::cin.fail() || std::cin.peek() != '\n' || numberValidation(a) || numberValidation(b))
    {
        std::cerr << "Error\n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return 1;
    }
    else
    {
        int numA = std::stoi(a);
        int numB = std::stoi(b);
        mySwap(&numA, &numB);
        std::cout << numA << " " << numB << std::endl;
        return 0;
    }
}