#include <iostream>
#include <string>
#include <cpr/cpr.h>

int main()
{
	std::string input;
	cpr::Response response;
	while (true)
	{
		std::cout << "Input your request: ";
		std::cin >> input;
		if (input == "get")
		{
			response = cpr::Get(cpr::Url("http://httpbin.org/get"));
		} else if (input == "post")
		{
			response = cpr::Post(cpr::Url("http://httpbin.org/post"));
		}else if (input == "put")
		{
			response = cpr::Put(cpr::Url("http://httpbin.org/put"));
		}else if(input == "delete")
		{
			response = cpr::Delete(cpr::Url("http://httpbin.org/delete"));
		}else if(input == "patch")
		{
			response = cpr::Patch(cpr::Url("http://httpbin.org/patch"));
		}else if(input == "exit")
		{
			std::cout << "Quitting the program" << std::endl;
			return 0;
		}else
		{
			std::cout << "Invalid input" << std::endl;
			return 1;
		}
		std::cout << response.text << std::endl;
	}
}
