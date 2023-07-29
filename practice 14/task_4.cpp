#include <iostream>
#include <vector>

void printVector(std::vector<int> &vector)
{
    for (int i = 0; i < 4; i++)
    {
        std::cout << vector[i] << " ";   
    }
    std::cout << std::endl;
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

std::vector<int> createVector()
{
    std::vector<int> vector(4);
    for (int i = 0; i < 4; i++)
    {
        std::cin >> vector[i];
    }
    return vector;
}

std::vector<int> multiplie(std::vector<std::vector<int>> &matrix, std::vector<int> &vector){
    std::vector<int> newVector(4, 0);
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            newVector[i] += matrix[i][j] * vector[j];
        }
    }
    return newVector;
}

int main()
{
    std::cout << "Input matrix: \n";
    std::vector<std::vector<int>> matrix = createMatrix();
    std::cout << "Input vector: \n";
    std::vector<int> vector = createVector();
    std::vector<int> resultVector = multiplie(matrix, vector);
    printVector(resultVector);
    return 0;
}