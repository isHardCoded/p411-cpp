#include <iostream>

class Shape {
	public:
		virtual double area() = 0;
		virtual double perimeter() = 0;
};

class Circle : public Shape {
	private:
		double radius;

	public:
		Circle(double r) : radius(r) {}

		double area() override {
			return 3.14 * radius * radius;
		}

		double perimeter() override {
			return 2 * 3.14 * radius;
		}
};

class Rectangle : public Shape {
	private:
		double width;
		double length;

	public:
		Rectangle(double w, double l) : width(w), length(l) {}

		double area() override {
			return width * length;
		}

		double perimeter() override {
			return (width + length) * 2;
		}
};

class Triangle : public Shape {
	private:
		double side1;
		double side2;
		double base;
		double height;

	public:
		Triangle(double b, double h, double s1, double s2) 
			: base(b), height(h), side1(s1), side2(s2) {}

		double area() override {
			return (base * height) / 2;
		}
		double perimeter() override {
			return side1 + side2 + base;
		}
};

int main()
{
	Shape* shapes[] = {
		new Circle(5),
		new Rectangle(2, 4),
		new Triangle(2, 3, 4, 5)
	};

	for (auto shape : shapes) {
		std::cout << "Area: " << shape->area() << std::endl;
		std::cout << "Perimeter: " << shape->perimeter() << std::endl;
	}
}

