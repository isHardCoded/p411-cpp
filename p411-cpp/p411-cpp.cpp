#include <iostream>

// Напишите программу на C++ для реализации класса под названием Circle, который имеет частные переменные членов для радиуса. 
// Включите функции членов для вычисления площади и окружности круга. 

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

