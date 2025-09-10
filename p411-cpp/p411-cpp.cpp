#include <iostream>

// Напишите программу на C++, чтобы создать класс под названием Прямоугольник, 
// который имеет частные переменные членов для длины и ширины. 
// Внедрение функций элемента для вычисления площади и периметра прямоугольника. 

class Rectangle {
	public:
		double length;
		double width;

		Rectangle(double length, double width) {
			this->length = length;
			this->width = width;
		}

		double area() {
			return length * width;
		}

		double perimeter() {
			return (length + width) * 2;
		}
};

int main()
{
	Rectangle r(5, 10);

	std::cout << "Area: " << r.area() << std::endl;
	std::cout << "Perimeter: " << r.perimeter() << std::endl;
}

