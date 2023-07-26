#include <cmath>
#include <iostream>
#include <limits>
#include <numeric>

int contain_symbol(std::string str, char sym)
{
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == sym)
        {
            return i;
        }
    }
    return -1;
}

std::string before_at(std::string str, char sym)
{
    std::string result = "";
    int matchIndex = contain_symbol(str, sym);
    if (matchIndex != -1)
    {
        for (int i = 0; i < matchIndex; i++)
        {
            result += str[i];
        }
    }
    return result;
}

std::string after_at(std::string str, char sym)
{
    std::string result = "";
    int matchIndex = contain_symbol(str, sym);
    if (matchIndex != -1)
    {
        for (int i = matchIndex + 1; i < str.length(); i++)
        {
            result += str[i];
        }
    }
    return result;
}
bool in_row(std::string str, char sym)
{

    for (int i = 1; i < str.length(); i++)
    {
        if (str[i] == str[i - 1] && str[i] == sym)
        {
            return true;
        }
    }
    return false;
}

bool correct_email(std::string emailAdress, std::string allowedCharsBeforePart, std::string allowedCharsAterPart, int defaultBeforeLength = 64, int defaultAfterLength = 63)
{
    std::string strBefore = before_at(emailAdress, '@');
    std::string strAfter = after_at(emailAdress, '@');
    if (strBefore.length() <= defaultBeforeLength && strBefore.length() > 0 && strAfter.length() > 0 && strAfter.length() <= defaultAfterLength 
        && strBefore[0] != '.' && strAfter[strAfter.length() - 1] != '.' 
        && !in_row(strBefore, '.') && !in_row(strAfter, '.'))
    {
        for (int i = 0; i < strBefore.length(); i++)
        {
            if (contain_symbol(allowedCharsBeforePart, strBefore[i]) == -1)
            {
                return false;
            }
        }
        for (int i = 0; i < strAfter.length(); i++)
        {
            if (contain_symbol(allowedCharsAterPart, strAfter[i]) == -1)
            {
                return false;
            }
        }
        return true;
    }
    return false;
}
int main()
{
    while (true)
    {
        std::string emailAddress;
        std::cout << "Input email adress: ";
        getline(std::cin, emailAddress);
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
            std::string allowedCharsBeforePart = "!#$%&'*+-/=?^_`{|}~.abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
            std::string allowedCharsAterPart = "-.abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
            std::cout << (correct_email(emailAddress, allowedCharsBeforePart, allowedCharsAterPart) ? "Yes\n" : "No\n");
            return 0;
        }
    }
}