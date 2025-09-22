#include <iostream>

// const_cast
void func(const int* p) {
	int* q = const_cast<int*>(p);
	*q = 10;
}

class MyClass {
	int value;

public:
	void setValue(int v) { value = v; }
	void printValue() const {
		std::cout << value << std::endl;
		const_cast<MyClass*>(this)->value = 10;
		std::cout << value;
	}
};

int main()
{
	int x = 5;
	const int y = 7;

	func(&x);
	func(&y);

	MyClass obj;
	obj.setValue(5);
	obj.printValue();
}

