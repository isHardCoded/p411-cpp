#include <iostream>
#include <cpr/cpr.h>

int main()
{
	std::string json_data = R"(
		{ 
			"name": "user1", 
			"firstname": "Tom", 
			"lastname": "Doe",
			"city": "Moscow",
			"avatar": "https://dogtowndogtraining.com/wp-content/uploads/2012/06/300x300-061-e1340955308953.jpg"
		}
	)";

	cpr::Response response = cpr::Post(
		cpr::Url { "https://6764432352b2a7619f5bfef7.mockapi.io/users" },
		cpr::Body { json_data },
		cpr::Header { { "Content-Type", "application/json" }}
	);

	if (response.status_code == 201) {
		std::cout << "Post created. Server response: " << std::endl << response.text << std::endl;
	}
	else {
		std::cout << "Error. Code: " << response.status_code << std::endl;
		std::cout << "Text: " << response.text << std::endl;
	}
}

