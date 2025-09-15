#include <iostream>
#include <string>

using namespace std;

class Phone {
	protected:
		string brand;
		string model;

		void turn_on() {
			cout << model << " is turn on" << endl;
		}

		virtual void show() {
			cout << "Brand: " << brand << endl;
			cout << "Model: " << model << endl;
		}

		Phone(string b, string m) : brand(b), model(m) {}
};

class IPhone : public Phone {
	protected:
		bool facetime;

	public:
		void show() override {
			cout << "Brand: " << brand << endl;
			cout << "Model: " << model << endl;
			cout << "Facetime: " << (facetime ? "Yes" : "No") << endl;
		}

		IPhone(string b, string m, bool f)
			: Phone(b, m), facetime(f) {
		}
};

int main()
{
	IPhone iphone("Apple", "Iphone X", true);
	iphone.show();
}

