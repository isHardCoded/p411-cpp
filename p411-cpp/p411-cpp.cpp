#include <iostream>

// �������� ��������� �� C++ ��� ���������� ������ ��� ��������� Circle, ������� ����� ������� ���������� ������ ��� �������. 
// �������� ������� ������ ��� ���������� ������� � ���������� �����. 

class Circle {
	public:
		double radius;

		Circle(double radius) {
			this->radius = radius;
		}

		double area() {
			return 3.14 * radius * radius;
		}

		double perimeter() {
			return 2 * 3.14 * radius;
		}
};

int main()
{
	Circle c(5);
	std::cout << "Area: " << c.area() << std::endl;
	std::cout << "Perimeter: " << c.perimeter() << std::endl;
}

