#include <iostream>
#include <limits>
#include <numeric>
#include <vector>

std::vector<std::vector<char>> gameInitialization()
{
    std::vector<std::vector<char>> gameField(3, std::vector<char>(3));
    for (int i = 0; i < gameField.size(); i++)
    {
        for (int j = 0; j < gameField.size(); j++)
        {
            gameField[i][j] = '*';
        }
    }
    return gameField;
}

void printGameField(std::vector<std::vector<char>> &gameField)
{
    for (int i = 0; i < gameField.size(); i++)
    {
        for (int j = 0; j < gameField.size(); j++)
        {
            std::cout << gameField[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

bool coordValidation(int x, int y)
{
    if (x < 0 || x > 2 || y < 0 || y > 2)
    {
        std::cout << "Wrong coordinate!\n";
        return false;
    }
    return true;
}

bool isFree(std::vector<std::vector<char>> &gameField, int x, int y)
{
    if (gameField[x][y] == '*')
    {
        return true;
    }
    std::cout << "This field is not free, try another.\n";
    return false;
}

bool isWin(std::vector<std::vector<char>> &gameField)
{
    int firstDiagonal = 0, secondDiagonal = 0, row = 0, column = 0;
    for (int i = 0; i < gameField.size(); i++)
    {
        for (int j = 0; j < gameField.size(); j++)
        {
            if (gameField[i][j] == 'X')
            {
                row++;
            }
            else if (gameField[i][j] == 'O')
            {
                row--;
            }

            if (gameField[j][i] == 'X')
            {
                column++;
            }
            else if (gameField[j][i] == 'O')
            {
                column--;
            }
        }
        if (gameField[i][i] == 'X')
        {
            firstDiagonal++;
        }
        else if (gameField[i][i] == 'O')
        {
            firstDiagonal--;
        }
        if (gameField[i][gameField.size() - i - 1] == 'X')
        {
            secondDiagonal++;
        }
        else if (gameField[i][gameField.size() - i - 1] == 'O')
        {
            secondDiagonal--;
        }
        if (row == 3 || column == 3 || firstDiagonal == 3 || secondDiagonal == 3)
        {
            return true;
        }
        else if (row == -3 || column == -3 || firstDiagonal == -3 || secondDiagonal == -3)
        {
            return true;
        }
        row = 0;
        column = 0;
    }
    return false;
}

int main()
{
    std::string choose = "No";
    std::cout << "Do you want to start new game? Type \"Yes\" or \"No\"\n";
    std::cin >> choose;
    while (choose != "No")
    {

        std::string firstPlayer, secondPlayer;
        std::cout << "Input first players name: ";
        std::cin >> firstPlayer;
        std::cout << "Input second players name: ";
        std::cin >> secondPlayer;
        std::vector<std::vector<char>> gameField = gameInitialization();
        printGameField(gameField);
        int movesNumber = 0;
        char gamerSymbol = 'X';
        std::string currentPlayer = firstPlayer;
        while (movesNumber < 9)
        {
            int x, y;
            std::cout << currentPlayer << "'s turn: ";
            std::cin >> x >> y;
            if (coordValidation(x, y) && isFree(gameField, x, y))
            {
                gameField[x][y] = gamerSymbol;
                printGameField(gameField);
                if (isWin(gameField))
                {
                    std::cout << currentPlayer << " wins!\n";
                    break;
                }
                else if (++movesNumber == 9)
                {
                    std::cout << "Draw!\n";
                    break;
                }
                else
                {
                    if (currentPlayer == firstPlayer)
                    {
                        gamerSymbol = 'O';
                        currentPlayer = secondPlayer;
                    }
                    else
                    {
                        gamerSymbol = 'X';
                        currentPlayer = firstPlayer;
                    }
                }
            }
        }
        std::cout << "Do you want to start new game? Type \"Yes\" or \"No\"\n";
        std::cin >> choose;
    }
    return 0;
}