#include <iostream>
#include <map>
#include <string>
#include <vector>

bool isWord(std::string &word)
{
    if (word.length() == 0)
        return false;
    for (int i = 0; i < word.length(); i++)
    {
        if (word[i] < 'A' || (word[i] > 'Z' && word[i] < 'a') || word[i] > 'z')
        {
            return false;
        }
    }
    return true;
}

bool isAnagram(std::string &first, std::string &second)
{
    std::map<char, int> word;
    if (first.length() != second.length())
    {
        return false;
    }
    for (int i = 0; i < first.length(); i++)
    {
        word[first[i]] += 1;
    }
    for (int i = 0; i < second.length(); i++)
    {
        if (word.empty())
        {
            return false;
        }
        else if (word.find((char)second[i]) != word.end())
        {
            word[second[i]] -= 1;
            if (word[second[i]] == 0)
            {
                word.erase(second[i]);
            }
        }
    }
    return word.empty();
}

int main()
{
    std::string first, second;
    std::cout << "Input first word: ";
    std::cin >> first;
    std::cout << "Input second word: ";
    std::cin >> second;
    if (!isWord(first) || !isWord(second))
    {
        std::cout << "Invalid input" << std::endl;
        return 1;
    }
    else
    {
        if (isAnagram(first, second))
        {
            std::cout << first << " is anagram of " << second << std::endl;
        }
        else
        {
            std::cout << first << " is not anagram of " << second << std::endl;
        }
    }
    return 0;
}