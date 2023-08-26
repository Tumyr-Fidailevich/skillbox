#include <iostream>
#include <cpr/cpr.h>

int main()
{
	cpr::Response response = cpr::Get(cpr::Url("http://httpbin.org/html"),
									  cpr::Header({{"accept", "text/html"}}));
	std::string responseText = response.text;
	int start = responseText.find("<h1>");
	int end = responseText.find("</h1>");
	std::cout << "Header: " << responseText.substr(start + 4, end - start - 4);
	return 0;
}
