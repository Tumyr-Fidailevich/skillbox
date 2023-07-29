#include <iostream>
#include <vector>

void printMatrix(std::vector<std::vector<int>> &matrix)
{
    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = 0; j < matrix.size(); j++)
        {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

std::vector<std::vector<int>> createSnakeMatrix(int dim)
{
    std::vector<std::vector<int>> matrix(dim, std::vector<int>(dim));
    int multiplier = 1;
    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = 0; j < matrix.size(); j++)
        {
            matrix[i][multiplier * j + (matrix.size() + multiplier) * (i % 2)] = i * 5 + j;
        }
        multiplier *= -1;
    }
    return matrix;
}

int main() {
    std::vector<std::vector<int>> snakeMatrix = createSnakeMatrix(5);
    printMatrix(snakeMatrix);
    return 0;
}