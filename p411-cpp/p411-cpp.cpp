#include <iostream>

class TodoItem {
	private:
		std::string description;
		bool completed;
		int id;

	public:
		static int todoCount;
		static int nextId;

		TodoItem(const std::string& desc) 
			: description(desc), completed(false), id(nextId++) {
			todoCount++;
		}

		void complete() {
			completed = true;
		}

		void print() const {
			std::cout << "ID: " << id << std::endl;
			std::cout << "Description: " << description << std::endl;
			std::cout << "Completed: " << (completed ? "Yes" : "No") << std::endl;
		}

		static int getTodoCount() {
			return todoCount;
		}
};

int TodoItem::todoCount = 0;
int TodoItem::nextId = 1;

int main()
{
	TodoItem t1("Todo 1");
	TodoItem t2("Todo 2");
	TodoItem t3("Todo 3");

	t2.complete();

	std::cout << "Todos count: " << TodoItem::getTodoCount() << std::endl;
}

