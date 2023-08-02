#include <iostream>
#include <limits>
#include <numeric>

enum note 
{ 
    DO = 1, 
    RE = 2, 
    MI = 4, 
    FA = 8, 
    SOL = 16, 
    LA = 32, 
    SI = 64 
};

bool inputValidation()
{
    if (std::cin.fail() || std::cin.peek() != '\n')
    {
        std::cerr << "Input error\n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return false;
    }
    else
    {
        return true;
    }
}

void printMelody(std::string melody[], int &size){
    for(int i = 0; i < size; i++){
        for(int j = 0; j < melody[i].length(); j++){
            int curNote = melody[i][j] - '0' - 1;
            if(1 << curNote & DO){
                std::cout << "DO" << " ";
            }else if((1 << curNote) & RE){
                std::cout << "RE" << " ";
            }else if((1 << curNote) & MI){
                std::cout << "MI" << " ";
            }else if((1 << curNote) & FA){
                std::cout << "FA" << " ";
            }else if((1 << curNote) & SOL){
                std::cout << "SOL" << " ";
            }else if((1 << curNote) & LA){
                std::cout << "LA" << " ";
            }else if((1 << curNote) & SI){
                std::cout << "SI" << " ";
            }
        }
        std::cout << std::endl;
    }
}

int main()
{   
    int size = 2;
    std::string melody[size];
    bool isValid = true;
    for(int i = 0; i < size; i++){
        std::cout << "Input your combination: ";
        std::cin >> melody[i];
        if(!inputValidation()) {
            return 1;
        }
    }  
    printMelody(melody, size);
    return 0;
}