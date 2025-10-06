#include <iostream>
#include <cpr/cpr.h>

class HttpClient {
	public:
		virtual cpr::Response get(const std::string& url) = 0;
		virtual cpr::Response post(
			const std::string& url, 
			const std::string& body, 
			const cpr::Header& headers
		) = 0;
};

class UserClient : public HttpClient {
	private:
		std::string base_url;

	public:
		UserClient(const std::string& base_url) : base_url(base_url) {}

		cpr::Response get(const std::string& url) override {
			return cpr::Get(cpr::Url{ url });
		}

		cpr::Response post(
			const std::string& url, 
			const std::string& body, 
			const cpr::Header& headers
		) override {
			return cpr::Post(cpr::Url{ url }, cpr::Body{ body }, headers);
		}

		cpr::Response getUsers() {
			return get(base_url + "/users");
		}

		cpr::Response createUser(
			const std::string& name, 
			const std::string& firstname, 
			const std::string& lastname, 
			const std::string& city) {

			std::string json_data = R"({
				"name": ")" + name + R"(",
				"firstname": ")" + firstname + R"(",
				"lastname": ")" + lastname + R"(",
				"city": ")" + city + R"("
			})";

			cpr::Header headers{ {"Content-Type", "application/json"} };

			return post(base_url + "/users", json_data, headers);
		}

		cpr::Response editUser(
			const std::string& user_id,
			const std::string& name,
			const std::string& firstname,
			const std::string& lastname,
			const std::string& city
		) {
			std::string json_data = R"({
				"name": ")" + name + R"(",
				"firstname": ")" + firstname + R"(",
				"lastname": ")" + lastname + R"(",
				"city": ")" + city + R"("
			})";

			cpr::Header headers{ {"Content-Type", "application/json"} };

			return cpr::Put(cpr::Url{ base_url + "/users/" + user_id }, cpr::Body{json_data}, headers);
		}
};

int main()
{
	UserClient client("https://6764432352b2a7619f5bfef7.mockapi.io");

	cpr::Response post_res = client.createUser("Tom123", "Tom", "Doe", "Moscow");
	std::cout << "[POST] status: " << post_res.status_code << std::endl;

	cpr::Response get_res = client.getUsers();
	std::cout << "[GET] status: " << get_res.status_code << std::endl;

	cpr::Response edit_res = client.editUser("14", "Tom123123123123123", "Tom", "Doe", "Tyumen");
	std::cout << "[PUT] status: " << edit_res.status_code << std::endl;
}

