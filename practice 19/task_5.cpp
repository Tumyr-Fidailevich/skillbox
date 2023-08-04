#include <fstream>
#include <iostream>
#include <vector>
#include <filesystem>

void showQuestion(std::string &absPath)
{
    std::ifstream text(absPath);
    if (text.is_open())
    {
        std::string line;
        while (std::getline(text, line))
        {
            std::cout << line << std::endl;
        }
    }
    text.close();
}

std::string getAnswer(std::string &absPath)
{
    std::string answer;
    std::ifstream text;
    text.open(absPath);
    getline(text, answer);
    text.close();
    return answer;
}

std::vector<int> initSectors()
{
    std::vector<int> sectors;
    for (int i = 0; i < 13; i++)
    {
        sectors.push_back(i + 1);
    }
    return sectors;
}

bool pathValidation(std::string &absPath)
{
    if (std::filesystem::exists(absPath) && std::filesystem::is_directory(absPath))
        return true;
    else
        return false;
}

int getSector(std::vector<int> &sectors, int arrow)
{
    int value;
    int i = arrow - 1;
    int count = 0;

    while (count < sectors.size())
    {
        i = i > 12 ? i = 0 : i;
        if (sectors[i] == 0)
        {
            i++;
            count++;
        }
        else
        {
            value = sectors[i];
            sectors[i] = 0;
            return value;
        }
    }
    return 0;
}

void game()
{
    std::vector<int> sectors = initSectors();
    std::string questionFolder;
    std::string answerFolder;
    while (!pathValidation(questionFolder) && !pathValidation(answerFolder))
    {
        std::cout << "Input question folder: ";
        std::getline(std::cin, questionFolder);
        std::cout << "Input answer folder: ";
        std::getline(std::cin, answerFolder);
    }
    int arrow = 1;
    std::cout << "Game has begun." << std::endl;
    int expertScore = 0;
    int viewerScore = 0;
    while (expertScore < 6 || viewerScore < 6)
    {
        std::cout << "Next turn." << std::endl;
        int offset;
        std::cout << "Input your offset: ";
        std::cin >> offset;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        arrow += offset;
        arrow = arrow > 13 ? arrow % 13 : arrow;
        int curSector = getSector(sectors, arrow);
        std::string questionPath = questionFolder + "\\question_sector_" + std::to_string(curSector) + ".txt";
        std::string answerPath = answerFolder + "\\answer_sector_" + std::to_string(curSector) + ".txt";
        showQuestion(questionPath);
        std::string answer;
        std::cout << "Your answer: ";
        getline(std::cin, answer);
        if (answer == getAnswer(answerPath))
        {
            expertScore++;
        }
        else
        {
            viewerScore++;
        }
    }
    if (expertScore > viewerScore)
    {
        std::cout << "Experts won" << std::endl;
    }
    else
    {
        std::cout << "Viewers won" << std::endl;
    }
}

int main()
{
    std::cout << "Question format: questions\\queistion_sector_i\n";
    std::cout << "Answer format: answers\\answer_sector_i\n";
    game();
    return 0;
}