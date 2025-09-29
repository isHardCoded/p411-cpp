#include <iostream>
#include <cpr/cpr.h>

int main()
{
	cpr::Response response = cpr::Get(cpr::Url{"https://jsonplaceholder.org/posts"});

	std::cout << response.text << std::endl;
}

