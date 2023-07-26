#include <cmath>
#include <iostream>
#include <limits>
#include <numeric>

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

std::string before_at(std::string str, char sym)
{
    std::string result = "";
    int matchIndex = contain_symbol(str, sym);
    if (matchIndex != -1)
    {
        for (int i = 0; i < matchIndex; i++)
        {
            result += str[i];
        }
    }
    return result;
}

std::string after_at(std::string str, char sym)
{
    std::string result = "";
    int matchIndex = contain_symbol(str, sym);
    if (matchIndex != -1)
    {
        for (int i = matchIndex + 1; i < str.length(); i++)
        {
            result += str[i];
        }
    }
    return result;
}

bool ip_validation(std::string ip){
    std::string allowedChar = "0123456789";
    std::string strBefore = before_at(ip, '.'), strAfter = after_at(ip, '.');
    int count = 0;
    while(strAfter.length() > 0 && count++ < 4){
        if(strBefore.length() == 0 || (strBefore.length() > 1 && strBefore[0] == '0')){
            return false;
        }else{
            int sum = 0;
            for(int i = 0; i < strBefore.length(); i++){
                if(contain_symbol(allowedChar, strBefore[i]) == -1){
                    return false;
                }else{
                    sum += (strBefore[i] - '0') * (pow(10, strBefore.length() - i - 1));
                }
            }
            if(sum >= 256){
                return false;
            }
        }
        if(count == 3){
            if(strAfter.length() == 0 || (strAfter.length() > 1 && strAfter[0] == '0')){
                return false;
            }else{
                int sum = 0;
                for(int i = 0; i < strAfter.length(); i++){
                    if(contain_symbol(allowedChar, strAfter[i]) == -1){
                        return false;
                    }else{ 
                        sum += (strAfter[i] - '0') * (pow(10, strAfter.length() - i - 1));
                    }
                }
                if(sum >= 256){
                    return false;
                }
            }
        }
        strBefore = before_at(strAfter, '.');
        strAfter = after_at(strAfter, '.');
    }
    return true;
}

int main() {
  while (true) {
    std::string ipAddress;
    std::cout << "Input your ip address: ";
    std::cin >> ipAddress;
    if (std::cin.fail() || std::cin.peek() != '\n') {
      std::cerr << "Error\n";
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      return 1;
    } else {
      std::cout << (ip_validation(ipAddress)? "Valid\n" : "Invalid\n");
      return 0;
    }
  }
}