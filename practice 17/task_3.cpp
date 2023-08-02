#include <iostream>
#include <limits>
#include <numeric>
#include <cstring>

bool substr(const char *str, const char *sub)
{
    int check = 0;
    for (int i = 0; i < strlen(str); i++)
    {
        if (*(str + i) == *(sub + check))
        {
            check++;
        }
        else if (check == strlen(sub))
        {
            return true;
        }
        else
        {
            check = 0;
        }
    }
    return false;
}

int main()
{
    const char *a = "Hello world";
    const char *b = "wor";
    const char *c = "banana";
    std::cout << "Result: " << (substr(a, b) ? "true" : "false") << " " << (substr(a, c) ? "true" : "false");
    return 0;
}