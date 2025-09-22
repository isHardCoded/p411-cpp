#include <iostream>

class Employee {
	private:
		std::string name;
		int id;

		static int employeeCount;
		static int nextId;

	public:
		Employee(const std::string& employeeName) : name(employeeName) {
			id = nextId++;
			employeeCount++;
		}

		int getId() const {
			return id;
		}

		std::string getName() const {
			return name;
		}

		static int getEmployeeCount() {
			return employeeCount;
		}
};

int Employee::nextId = 1;
int Employee::employeeCount = 0;

int main()
{
	Employee e1("Tom");
	Employee e2("Tim");
	Employee e3("Sam");

	std::cout << e1.getId();
	std::cout << e2.getId();
	std::cout << e3.getId();

	std::cout << Employee::getEmployeeCount();
}

