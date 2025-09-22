#include <iostream>

// cast

// static_cast
class Base {};
class Derived : public Base {};

int main()
{
	int i = 10;
	double d = static_cast<double>(i);

	int x = 5, y = 2;
	double result = static_cast<double>(x) / y;

	char c = 'A';
	int ascii = static_cast<int>(c);

	std::cout << result;

	Base* b = new Derived();
	Derived* d = static_cast<Derived*>(b);
}

