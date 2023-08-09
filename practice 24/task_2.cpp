#include <iostream>
#include <ctime>
#include <iomanip>
#include <vector>

struct Friend
{
    std::string name;
    std::tm birthdayTM;
};

void list_friends(std::vector<Friend> &friends)
{
    if (friends.size() > 0)
    {
        std::time_t curTime = std::time(nullptr);
        std::tm curTimeTM = *std::localtime(&curTime);
        int max = 0;
        for (int i = 1; i < friends.size(); i++)
        {
            int dt = friends[i].birthdayTM.tm_yday - curTimeTM.tm_yday;
            if (dt == 0)
            {
                std::cout << friends[i].name << "has birthday today" << std::endl;
            }
            else if (dt > 0 && dt < friends[i - 1].birthdayTM.tm_yday - curTimeTM.tm_yday)
            {
                max = i;
            }
        }
        if (friends[max].birthdayTM.tm_yday > curTimeTM.tm_yday)
        {
            std::cout << friends[max].name << "'s birthday will be " << std::put_time(&friends[max].birthdayTM, "%m/%d") << std::endl;
        }
    }
}

int main()
{
    std::vector<Friend> friends;
    std::string name;
    std::time_t birthday = std::time(nullptr);
    std::cout << "Input name: ";
    std::cin >> name;
    while (name != "end")
    {
        Friend curFriend;
        curFriend.name = name;
        curFriend.birthdayTM = *std::localtime(&birthday);
        std::cout << "Input birthday: ";
        std::cin >> std::get_time(&(curFriend.birthdayTM), "%Y/%m/%d");
        friends.push_back(curFriend);
        std::cout << "Input name: ";
        std::cin >> name;
    }
    list_friends(friends);
    return 0;
}