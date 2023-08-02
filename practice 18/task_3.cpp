#include <cmath>
#include <iostream>
#include <limits>
#include <numeric>

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

void evendigits(long long number, int &answer)
{
    if (number != 0)
    {
        if (number % 2 == 0){
            answer++;
        }
        return evendigits(number / 10, answer);
    }
    else
    {
        return;
    }
}

int main()
{
    std::string input;
    std::cout << "Input number: ";
    std::cin >> input;
    if (numberValidation(input))
    {
        int answer = 0;
        evendigits(std::stoll(input), answer);
        std::cout << "Your number has " << answer << " even digits.\n";
    }
}