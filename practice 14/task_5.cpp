#include <iostream>
#include <vector>

bool printMatrix(std::vector<std::vector<bool>> &matrix)
{
    bool bubbleExist = false;
    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = 0; j < matrix.size(); j++)
        {
            if (matrix[i][j])
            {
                std::cout << "o ";
                bubbleExist = true;
            }
            else
            {
                std::cout << "x ";
            }
        }
        std::cout << std::endl;
    }
    return bubbleExist;
}

std::vector<std::vector<bool>> createMatrix()
{
    std::vector<std::vector<bool>> matrix(12, std::vector<bool>(12, true));
    return matrix;
}

bool coordValidation(int x_0, int y_0, int x_1, int y_1)
{
    if (x_0 < 0 || x_0 > 11 || y_0 < 0 || y_0 > 11 || x_0 > x_1 || y_0 > y_1 || y_1 > 11 || x_1 > 11)
    {
        return false;
        std::cout << "Wrong coordinates!\n";
    }
    return true;
}

void pop(std::vector<std::vector<bool>> &matrix, int x_0, int y_0, int x_1, int y_1)
{
    if (coordValidation(x_0, y_0, x_1, y_1))
    {
        for (int i = x_0; i <= x_1; i++)
        {
            for (int j = y_0; j <= y_1; j++)
            {
                matrix[i][j] = false;
            }
        }
    }
}

int main()
{
    std::vector<std::vector<bool>> matrix = createMatrix();
    while (printMatrix(matrix))
    {
        std::cout << "Input start coordinate: ";
        int x_0, y_0;
        std::cin >> x_0 >> y_0;
        std::cout << "Input end coordinate: ";
        int x_1, y_1;
        std::cin >> x_1 >> y_1;
        pop(matrix, x_0, y_0, x_1, y_1);
    }
    return 0;
}