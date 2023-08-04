#include <fstream>
#include <iostream>
#include <numeric>
#include <limits>

int wordCount(std::string &userWord, std::string &absPath)
{
    std::ifstream text;
    int count = 0;
    text.open(absPath);
    if (text.is_open())
    {
        while (!text.eof())
        {
            std::string word;
            text >> word;
            if (word == userWord)
            {
                count++;
            }
        }
        text.close();
        return count;
    }
    else
    {
        text.close();
        return 0;
    }
}

int main()
{
    std::string userWord;
    std::cout << "Input your word: ";
    std::cin >> userWord;
    std::string path;
    std::cout << "Input your path: ";
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    getline(std::cin, path);
    std::cout << "This word occurs " << wordCount(userWord, path) << " times\n";
    return 0;
}