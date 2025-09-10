#include <iostream>

// Напишите программу на C++, чтобы создать класс под названием «Человек», 
// который имеет частные переменные для имени, возраста и страны. 
// Внедрение функций членов для установки и получения значений этих переменных. 

class Human {

	private:
		std::string name;
		int age;
		std::string country;

	public:
		Human(std::string name, int age, std::string country) {
			this->name = name;
			this->age = age;
			this->country = country;
		}

		std::string getName() {
			return name;
		}

		std::string getCountry() {
			return country;
		}

		int getAge() {
			return age;
		}

		void setName(std::string value) {
			name = value;
		}

		void setCountry(std::string value) {
			country = value;
		}

		void setAge(int value) {
			age = value;
		}

		void show() {
			std::cout << "Name: " << name << std::endl;
			std::cout << "Age: " << age << std::endl;
			std::cout << "Country: " << country << std::endl;
		}
};

int main()
{
	Human h("John", 25, "USA");	
	h.show();
}

