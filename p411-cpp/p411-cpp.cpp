#include <iostream>

class Character {
	public:
		std::string name;
		int level;
		double mana;
		bool isAlive;
};

int main()
{
	Character character;

	character.name = "John";
	character.level = 5;
	character.mana = 10.5;
	character.isAlive = true;

	std::cout << "Name: " << character.name << std::endl;
	std::cout << "Level: " << character.level << std::endl;
	std::cout << "Mana: " << character.mana << std::endl;
	std::cout << "Is alive: " << character.isAlive << std::endl;
}

