#include <cmath>
#include <iostream>
#include <limits>
#include <numeric>

char find_symbol(std::string firstRow, std::string secondRow, std::string thirdRow, int x, int y){
    if(x == 0){
        if(y >= firstRow.length() || y < 0){
            std::cout << "Invalid coordinates\n";
        }else{
            return firstRow[y];
        }
    }else if(x == 1){
        if(y >= secondRow.length() || y < 0){
            std::cout << "Invalid coordinates\n";
        }else{
            return secondRow[y];
        }
    }else if(x == 2){
        if(y >= thirdRow.length() || y < 0){
            std::cout << "Invalid coordinates\n";
        }else{
            return thirdRow[y];
        }
    }else{
        std::cout << "Invalid coordinates\n";
    }
    return ' ';
}

int contain_symbol(std::string str, char sym)
{
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == sym)
        {
            return i;
        }
    }
    return -1;
}

bool game_validation(std::string firstRow, std::string secondRow, std::string thirdRow){
    if(firstRow.length() != 3 || secondRow.length() != 3 || thirdRow.length() != 3){
        return false;
    }else{
        int crossCount = 0;
        int zeroCount = 0;
        for(int i = 0; i < firstRow.length(); i++){
            if(contain_symbol("XO.", firstRow[i]) == -1 || contain_symbol("XO.", secondRow[i]) == -1 || contain_symbol("XO.", thirdRow[i]) == -1){
                return false;
            }
            if (firstRow[i] == 'X'){
                crossCount++;
            }else if(firstRow[i] == 'O'){
                zeroCount++;
            }
            if (secondRow[i] == 'X'){
                crossCount++;
            }else if(secondRow[i] == 'O'){
                zeroCount++;
            }
            if (thirdRow[i] == 'X'){
                crossCount++;
            }else if(thirdRow[i] == 'O'){
                zeroCount++;
            }
        }
        if(crossCount - zeroCount != 1 && crossCount - zeroCount != 0){
            return false;
        }
    }
    return true;
}
std::string who_wins(std::string firstRow, std::string secondRow, std::string thirdRow, std::string firstPlayer, std::string secondPlayer){
    if(game_validation(firstRow, secondRow, thirdRow)){
        int first_diagonal = 0;
        int second_diagonal = 0;
        int row = 0;
        int column = 0;
        int cross = 0;
        int zero = 0;
        bool crossWins = false;
        bool zeroWins = false;
        for(int i = 0; i < firstRow.length(); i++){
            if(find_symbol(firstRow, secondRow, thirdRow, i, i) == 'X'){
                first_diagonal++;
            }else if(find_symbol(firstRow, secondRow, thirdRow, i, i) == 'O'){
                first_diagonal--;
            }
            if(find_symbol(firstRow, secondRow, thirdRow, i, firstRow.length() - i - 1) == 'X'){
                second_diagonal++;
            }else if(find_symbol(firstRow, secondRow, thirdRow, i, firstRow.length() - i - 1) == 'O'){
                second_diagonal--;
            }
            if(first_diagonal == 3 || second_diagonal == 3) crossWins = true;
            else if(first_diagonal == -3 || second_diagonal == -3) zeroWins = true;
            for (int j = 0; j < firstRow.length(); j ++){
                if(find_symbol(firstRow, secondRow, thirdRow, i, j) == 'X'){
                    row++;
                    cross++;
                }else if(find_symbol(firstRow, secondRow, thirdRow, i, j) == 'O'){
                    row--;
                }
                if(find_symbol(firstRow, secondRow, thirdRow, j, i) == 'X'){
                    column++;
                    
                }else if(find_symbol(firstRow, secondRow, thirdRow, j, i) == 'O'){
                    column--;
                    zero++;
                }
            }
            if(row == 3 || column == 3){
                crossWins = true;
            }else if(row == -3 || column == -3) {
                zeroWins = true;
            }
            row = 0;
            column = 0;
        }
        if(crossWins && cross == zero || zeroWins && zero != cross){
            return "Incorrect\n";
        }else if(crossWins){
            return firstPlayer + " won\n";
        }else if(zeroWins){
            return secondPlayer + " won\n";
        }else{
            return "Nobody\n";
        }
    }else{
        return "Incorrect\n";
    }
}
int main()
{

    while (true)
    {
        std::string firstRow, secondRow, thirdRow;
        std::cout << "Input game field: \n";
        std::cin >> firstRow;
        std::cin >> secondRow;
        std::cin >> thirdRow;
        if (std::cin.fail() || std::cin.peek() != '\n')
        {
            std::cerr << "Error\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return 1;
        }
        else
        {
            std::cout << who_wins(firstRow, secondRow, thirdRow, "Petya", "Vasya");
            return 0;
        }
    }
}