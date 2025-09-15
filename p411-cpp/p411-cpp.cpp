#include <iostream>
#include <string>
#include <vector>

class Student {
	private:
		int id;
		std::string name;
		std::string _class;
		std::vector<double> grades;

	public:
		Student(int id, const std::string& name, const std::string& _class) {
			this->id = id;
			this->name = name;
			this->_class = _class;
		}

		void addMark(int grade) {
			grades.push_back(grade);
		}

		double getAverageGrade() {
			if (grades.empty()) {
				return 0.0;
			}

			int sum = 0;
			for (int grade : grades) {
				sum += grade;
			}

			return sum / (0.0 + grades.size());
		}

		void show() {
			std::cout << "Student [" << id << "]: " << name << std::endl;
			std::cout << "Grades [ ";
			for (int grade : grades) {	
				std::cout << grade << " ";
			}
			std::cout << "]" << std::endl;
			std::cout << "Average grade: " << getAverageGrade() << std::endl;
		}
};

int main()
{
	Student st1(1, "Tom", "1B");
	st1.addMark(5);
	st1.addMark(5);
	st1.addMark(5);
	st1.addMark(2);

	st1.show();
}

