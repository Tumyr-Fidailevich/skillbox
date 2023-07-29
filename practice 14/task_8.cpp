#include <iostream>
#include <vector>

int distance(int startX, int startY, int endX, int endY)
{
    return (endX - startX) * (endX - startX) + (endY - startY) * (endY - startY);
}

void printGameField(std::vector<std::vector<char>> &gameField, std::string &playerName)
{
    std::cout << playerName << "'s game field\n";
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
    if (x < 0 || x > 9 || y < 0 || y > 9)
    {
        return false;
        std::cout << "Wrong coordinates!\n";
    }
    return true;
}

bool shoot(std::vector<std::vector<char>> &gameField, int &x, int &y)
{
    if (gameField[x][y] == 'X')
    {
        std::cout << "You hit\n";
        gameField[x][y] = '*';
        return true;
    }
    else
    {
        std::cout << "You miss\n";
        gameField[x][y] = '*';
        return false;
    }
}

bool shipCoordValidation(int startX, int startY, int endX, int endY, int size)
{
    return coordValidation(startX, startY) && coordValidation(endX, endY) &&
           &&distance(startX, startY, endX, endY) == (size - 1) * (size - 1);
}

void insertShip(std::vector<std::vector<char>> &gameField, int size)
{
    int k = 1;
    while (k <= 5 - size)
    {
        int x, y, x_0, y_0;
        std::cout << "Input coordinates of " << k << " " << size << " cell ship: ";
        if (size == 1)
        {
            std::cin >> x_0 >> y_0;
            x = x_0;
            y = y_0;
        }
        else
        {
            std::cout << "Start coordinates: ";
            std::cin >> x_0 >> y_0;
            std::cout << "End coordinates: ";
            std::cin >> x >> y;
        }
        if (shipCoordValidation(x_0, y_0, x, y, size))
        {
            for (int i = x_0; i < x; i++)
            {
                for (int j = y_0; j < y; j++)
                {
                    gameField[i][j] = 'X';
                }
            }
            k++;
        }
    }
}

std::vector<std::vector<char>> gameInitialization()
{
    std::vector<std::vector<char>> gameField(10, std::vector<char>(10));
    for (int i = 0; i < gameField.size(); i++)
    {
        for (int j = 0; j < gameField.size(); j++)
        {
            gameField[i][j] = '*';
        }
    }
    std::cout << "You can't place ships diagonally\n";
    for (int shipSize = 1; i <= 4; i++)
    {
        insertShip(gameField, shipSize);
    }
    return gameField;
}

bool isWin(std::vector<std::vector<char>> &gameField)
{
    for (int i = 0; i < gameField.size(); i++)
    {
        for (int j = 0; j < gameField.size(); j++)
        {
            if (gameField[i][j] == 'X')
            {
                return false;
            }
        }
    }
    return true;
}

bool gameMove(std::vector<std::vector<char>> &gameField)
{
    int x, y;
    std::cout << "Input coordinates for your strike: ";
    std::cin >> x >> y;
    return coordValidation(x, y) && shoot(gameField, x, y);
}
int main()
{
    std::string firstPlayer, secondPlayer;
    std::cout << "Input first players name: ";
    std::cin >> firstPlayer;
    std::cout << "Input second players name: ";
    std::cin >> secondPlayer;
    std::vector<std::vector<char>> firstPlayerGameField = gameInitialization();
    std::vector<std::vector<char>> secondPlayerGameField = gameInitialization();
    printGameField(firstPlayerGameField, firstPlayer);
    printGameField(secondPlayerGameField, secondPlayer);
    std::string currentPlayer = firstPlayer;
    while (!(isWin(firstPlayerGameField) || isWin(secondPlayerGameField)))
    {
        if (currentPlayer == firstPlayer)
        {
            if(!gameMove(secondPlayerGameField)){
                currentPlayer = secondPlayer;
            }
        }
        else
        {
            if(!gameMove(firstPlayerGameField)){
                currentPlayer = firstPlayer;
            }
        }
    }
    printGameField(firstPlayerGameField, firstPlayer);
    printGameField(secondPlayerGameField, secondPlayer);
    std::cout << currentPlayer << " won!\n";
}