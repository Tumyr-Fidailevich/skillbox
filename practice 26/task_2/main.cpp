#include <iostream>
#include <string>
#include <map>

class Number {
private:
    std::string countryCode = "7";
    std::string regionCode;
    std::string cityNumber;
public:
    void setNumber(std::string &input) {
        if (!input.empty() && input.size() == 12 && input[0] == '+') {
            countryCode = input[1];
            regionCode = input.substr(2, 3);
            cityNumber = input.substr(5);
        } else {
            std::cout << "Invalid number format" << std::endl;
        }
    }

    std::string getNumber() {
        std::string number = "+" + countryCode + regionCode + cityNumber;
        return number;
    }
};

class Phone {
private:
    std::map<std::string, Number> addressBook;

    int isExist(std::string &input) {
        if (addressBook.find(input) != addressBook.end()) {
            return 1;
        } else {
            for (auto &it: addressBook) {
                if (it.second.getNumber() == input) {
                    return 0;
                }
            }
            return -1;
        }
    }

public:
    void add(std::string &name, std::string &number) {
        Number num;
        num.setNumber(number);
        addressBook.insert({name, num});
    }

    void call(std::string &input) {
        if (isExist(input) == 1) {
            std::cout << "Call: " << addressBook[input].getNumber() << std::endl;
        } else if (isExist(input) == 0) {
            std::cout << "Call: " << input << std::endl;
        } else {
            std::cout << "This phone number or subscriber does not exist in the address book" << std::endl;
        }
    }

    void sms(std::string &input) {
        std::cin.ignore();
        if (isExist(input) == 1) {
            std::string text;
            std::cout << "Input your text: ";
            std::getline(std::cin, text);
            std::cout << "Sms to " << addressBook[input].getNumber() << " : " << text << std::endl;
        } else if (isExist(input) == 0) {
            std::string text;
            std::cout << "Input your text: ";
            std::getline(std::cin, text);
            std::cout << "Sms to " << input << " : " << text << std::endl;
        } else {
            std::cout << "This phone number or subscriber does not exist in the address book" << std::endl;
        }
    }
};

int main() {
    std::string input;
    auto phone = new Phone;
    while (true) {
        std::cout << "Input command: ";
        std::cin >> input;
        if (input == "add") {
            std::string name, number;
            std::cout << "Input name: ";
            std::cin >> name;
            std::cout << "Input number: ";
            std::cin >> number;
            phone->add(name, number);
        } else if (input == "call") {
            std::string name;
            std::cout << "Input name or number: ";
            std::cin >> name;
            phone->call(name);
        } else if (input == "sms") {
            std::string name;
            std::cout << "Input name or number: ";
            std::cin >> name;
            phone->sms(name);
        } else if (input == "exit") {
            std::cout << "Quitting the program" << std::endl;
            delete phone;
            phone = nullptr;
            return 0;
        } else {
            std::cout << "Wrong input" << std::endl;
            delete phone;
            phone = nullptr;
            return 1;
        }
    }
}
