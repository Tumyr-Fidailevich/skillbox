#include <cmath>
#include <iostream>
#include <limits>
#include <numeric>
int sgn(int n){
  return (n > 0 ? 1 : (n == 0 ? 0 : -1));
}

std::string encrypt_caesar(std::string str, int offset)
{
  std::string result = "";
  offset %= 26;
  for (int i = 0; i < str.length(); i++)
  {
    char currentLetter = str[i] + offset;
    if (str[i] >= 'A' && str[i] <= 'Z')
    {
      if (currentLetter > 'Z' || currentLetter < 'A')
      {
        currentLetter -= sgn(currentLetter - 'A') * ('Z' - 'A' + 1);
      }
      result += (char)(currentLetter);
    }
    else if (str[i] >= 'a' && str[i] <= 'z')
    {
      if (currentLetter > 'z' || currentLetter < 'a')
      {
        currentLetter -= sgn(currentLetter - 'a') * ('z' - 'a' + 1) ;
      }
      result += (char)(currentLetter);
    }else{
      result += str[i];
    }
  }
  return result;
}

std::string decrypt_caesar(std::string str, int offset)
{
  return encrypt_caesar(str, -offset);
}

int main()
{
  while (true)
  {
    std::string text;
    int offset;
    std::cout << "Input your text: ";
    getline(std::cin, text);
    std::cout << "Input your offset: ";
    std::cin >> offset;
    if (std::cin.fail() || std::cin.peek() != '\n')
    {
      std::cerr << "Error\n";
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      return 1;
    }
    else
    {
      std::string encryptedText = encrypt_caesar(text, offset);
      std::cout << "Encrypted text: " << encryptedText << std::endl;
      std::cout << "Decrypted text: " << decrypt_caesar(encryptedText, offset) << std::endl;
      return 0;
    }
  }
}