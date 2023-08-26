#include <iostream>
#include <cpr/cpr.h>
#include <string>
#include <map>
#include <vector>

int main()
{
	std::string argument, value;
	std::map<std::string, std::string> arguments;
	cpr::Response response;
	while(true)
	{
		std::cout << "Argument: ";
		std::cin >> argument;
		if(argument == "post" || argument == "get") break;
		std::cout << "Value: ";
		std::cin >> value;
		arguments.insert({argument, value});
	}
	std::map<std::string, std::string>::iterator it;
	if(argument == "post")
	{
		std::vector<cpr::Pair> pairs;
		for(it = arguments.begin(); it != arguments.end(); it++)
		{
			pairs.emplace_back(it->first, it->second);
		}
		response = cpr::Post(cpr::Url("http://httpbin.org/post"),
				cpr::Payload(pairs.begin(), pairs.end()));
	}else if(argument == "get")
	{

		std::string url = "http://httpbin.org/get?";
		for(it = arguments.begin(); it != arguments.end(); it++)
		{
			url += it->first + "=" + it->second + "&";
		}
		response = cpr::Get(cpr::Url(url.c_str()));
	}
	std::cout << response.text << std::endl;
	return 0;
}
