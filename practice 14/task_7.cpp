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

std::vector<std::vector<int>> createMatrix()
{
    std::vector<std::vector<int>> matrix(5, std::vector<int>(5));
    for (int i = 0; i < 5; i++)
    {
        std::string input;
        getline(std::cin, input);
        int j = 4;
        while(!input.empty() && j >= 0){
            if(input.back() >= '0'){
                matrix[i][j] = input.back() - '0';
                j--;
            }
            input.pop_back();
        }
    }
    return matrix;
}

std::vector<std::vector<std::vector<int>>> createMatrixByHeights()
{
    std::cout << "Input matrix of heights: \n";
    std::vector<std::vector<int>> heightsMatrix = createMatrix();
    std::vector<std::vector<std::vector<int>>> resultMatrix(10, std::vector<std::vector<int>>(5, std::vector<int>(5, 0)));
    for (int k = 0; k < 10; k++)
    {
        for (int i = 0; i < heightsMatrix.size(); i++)
        {
            for (int j = 0; j < heightsMatrix.size(); j++)
            {
                if(heightsMatrix[i][j] >= k){
                    resultMatrix[k][i][j] = 1;
                }
            }
        }
    }
    return resultMatrix;
}

int main()
{
    std::vector<std::vector<std::vector<int>>> matrix3D = createMatrixByHeights();
    int slice;
    std::cout << "Input slice: ";
    std::cin >> slice;
    while(slice != -1){
        if(slice < 10 && slice >= 0){
            printMatrix(matrix3D[slice]);
        }else{
            std::cout << "Wrong index\n";
        }
        std::cout << "Input slice: ";
        std::cin >> slice;
    }
    return 0;
}