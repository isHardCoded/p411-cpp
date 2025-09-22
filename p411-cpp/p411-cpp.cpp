#include <iostream>

class Animal {
public:
	virtual void sound() {
		std::cout << "Animal makes sound";
	}
};

class Dog : public Animal {
public:
	void sound() override {
		std::cout << "Dog barks";
	}

	void fetch() {
		std::cout << "Dog fethes ball";
	}
};

class Cat : public Animal {
public:
	void sound() override {
		std::cout << "Cat meow";
	}
};

int main()
{
	Dog dog;
	Animal* animalPtr = &dog;

	Dog* dogPtr = static_cast<Dog*>(animalPtr);

	dogPtr->fetch();
}

