#include <iostream>

// Напишите программу на C++ для реализации класса под названием BankAccount, 
// который имеет частные переменные для числа участников счета и баланса. 
// Включите функции участников для внесения и снятия денег со счета. 

class BankAccount {
	private:
		std::string accountNumber;
		double balance;

	public:
		BankAccount(std::string accountNumber, double balance) {
			this->accountNumber = accountNumber;
			this->balance = balance;
		}

		void deposit(double amount) {
			balance += amount;
		}

		void withdraw(double amount) {
			if (amount > 0) {
				std::cout << amount << " > " << balance << std::endl;
			}
			else {
				balance -= amount;
			}
		}

		void show() {
			std::cout << "Account number: " << accountNumber << std::endl;
			std::cout << "Balance: " << balance << std::endl;
		}
};

int main()
{
	BankAccount ba("411", 0);
	ba.show();

	ba.withdraw(1000000);

	ba.show();
}

