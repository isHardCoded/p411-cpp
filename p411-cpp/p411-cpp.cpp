#include <iostream>

// �������� ��������� �� C++, ����� ������� ����� ��� ��������� Car, 
// ������� ����� ������� ���������� ��� ��������, ������ � ����. 
// ��������� ������� ������ ��� ��������� � ��������� ���� ����������. 

class Car {
	private:
		std::string company;
		std::string model;
		int year;

	public:
		Car(std::string company, std::string model, int year) {
			this->company = company;
			this->model = model;
			this->year = year;
		}

		std::string getCompany() {
			return company;
		}

		std::string getModel() {
			return model;
		}

		int getYear() {
			return year;
		}

		void setCompany(std::string value) {
			company = value;
		}

		void setModel(std::string value) {
			model = value;
		}

		void setYear(int value) {
			year = value;
		}

		void show() {
			std::cout << "Company: " << company << std::endl;
			std::cout << "Model: " << model << std::endl;
			std::cout << "Year: " << year << std::endl;
			std::cout << std::endl;
		}
};

int main()
{
	Car c("Toyota", "Camry", 2022);
	
	c.show();
}

