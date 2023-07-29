#include <iostream>
#include <limits>
#include <numeric>
#include <vector>

void printMatrix(std::vector<std::vector<int>> &matrix)
{
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

std::vector<std::vector<int>> createMatrix()
{
    std::vector<std::vector<int>> matrix(4, std::vector<int>(4));
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            std::cin >> matrix[i][j];
        }
    }
    return matrix;
}

bool isEqual(std::vector<std::vector<int>> &firstMatrix, std::vector<std::vector<int>> &secondMatrix)
{
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (firstMatrix[i][j] != secondMatrix[i][j])
            {
                std::cout << "Matrix are not equal!\n";
                return false;
            }
        }
    }
    std::cout << "Matrix are equal!\n";
    return true;
}

void toDiagonal(std::vector<std::vector<int>> &matrix)
{
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (i != j)
            {
                matrix[i][j] = 0;
            }
        }
    }
}

int main()
{
    std::vector<std::vector<int>> firstMatrix;
    std::vector<std::vector<int>> secondMatrix;
    std::cout << "Input first matrix: ";
    firstMatrix = createMatrix();
    std::cout << "Input second matrix: ";
    secondMatrix = createMatrix();
    if(isEqual(firstMatrix, firstMatrix)){
        toDiagonal(firstMatrix);
        printMatrix(firstMatrix);
    }
    return 0;
}