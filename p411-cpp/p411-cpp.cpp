#include <iostream>

// Напишите программу на C++, чтобы создать класс под названием Треугольник, 
// который имеет частные переменные членов для длин трех сторон. 
// Реализуйте функции элемента, чтобы определить, 
// является ли треугольник равносторонним, изосцеленным или масштабируемым. 

class Triangle {
	private:
		double side1;
		double side2;
		double side3;

	public:
		Triangle(double side1, double side2, double side3) {
			this->side1 = side1;
			this->side2 = side2;
			this->side3 = side3;
		}

		bool isEquilateral() {
			return (side1 == side2) && (side2 == side3);
		}

		bool isIsosceles() {
			return (side1 == side2) || (side1 == side3) || (side2 == side3);
		}

		bool isScalene() {
			return (side1 != side2 && side2 != side3 && side1 != side3);
		}
};

int main()
{
	Triangle t(3, 3, 3);

	std::cout << t.isEquilateral() << std::endl;
	std::cout << t.isIsosceles() << std::endl;
	std::cout << t.isScalene() << std::endl;

}

