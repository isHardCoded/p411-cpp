#include <iostream>

class Character {
	public:
		std::string name;
		int level;
		double mana;
		bool isAlive;

		Character (std::string name, int level, double mana, bool isAlive) {
			this->name = name;
			this->level = level;
			this->mana = mana;
			this->isAlive = isAlive;
		}

		void show() {
			std::cout << "Name: " << name << std::endl;
			std::cout << "Level: " << level << std::endl;
			std::cout << "Mana: " << mana << std::endl;
			std::cout << "Is alive: " << isAlive << std::endl;
			std::cout << std::endl;
		}
};

int main()
{
	Character* characters[] = {
		new Character("John", 5, 10.5, true),
		new Character("Tom", 4, 2.5, false),
		new Character("Tim", 12, 32.5, true),
		new Character("Jim", 7, 14.5, true),
		new Character("Bob", 1, 1, true)
	};

	for (auto character : characters) {
		character->show();
	}
}

