#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

class Book {
	protected:
		std::string title;
		std::string author;
		std::string ISBN;
		bool available;

	public:
		Book(const std::string& t, const std::string& a, const std::string& i)
			: title(t), author(a), ISBN(i), available(true) {}

		bool checkAvailability() const {
			return available;
		}

		void setAvailability(bool avail) {
			available = avail;
		}

		virtual std::string str() const {
			return "Book: " + title + ", author: " + author + ", ISBN: " + ISBN + ", available" + (available ? "Yes" : "No");
		}
};

class EBook : public Book {
	private:
		std::string fileFormat;

	public:
		EBook(const std::string& t, const std::string& a, const std::string& i, const std::string format)
			: Book(t, a, i), fileFormat(format) {}

		std::string getFileFormat() const {
			return fileFormat;
		}

		std::string str() const override {
			return "Book: " + title + ", author: " + author + ", ISBN: " + ISBN + ", Format: " + fileFormat + ", available" + (available ? "Yes" : "No");
		}
};

class PrintedBook : public Book {
	private:
		int pageCount;

	public:
		PrintedBook(
			const std::string& t,
			const std::string& a,
			const std::string& i,
			const std::string format,
			int pc) : Book(t, a, i), pageCount(pc) {
		}

		int getPageCount() const {
			return pageCount;
		}

		std::string str() const override {
			return "Book: " + title + ", author: " + author + ", ISBN: " + ISBN + ", Page count: " + std::to_string(pageCount) + ", available" + (available ? "Yes" : "No");
		}
};

class Reader {
	private:
		std::string name;
		int reader_id;
		std::vector<Book*> borrowedBooks;

	public:
		Reader(const std::string& n, int id) : name(n), reader_id(id) {}

		void borrowBook(Book* book) {
			if (book->checkAvailability()) {
				borrowedBooks.push_back(book);
				book->setAvailability(false);

				std::cout << name << " borrowed" << book->str() << std::endl;
			}

			else {
				std::cout << "Book is not available" << std::endl;
			}
		}

		void returnBook(Book* book) {
			auto it = find(borrowedBooks.begin(), borrowedBooks.end(), book);

			if (it != borrowedBooks.end()) {
				borrowedBooks.erase(it);
				(*it)->setAvailability(true);
				

				std::cout << name << " returned" << std::endl;
			}

			else {
				std::cout << (*it)->str() << " not borrowed by " << name << std::endl;
			}
		}

		std::string str() const {
			std::string result = "Reader: " + name + "\nBorrowed books:";

			if (borrowedBooks.empty()) result += "None";

			for (auto book : borrowedBooks) {
				result += "\n - " + book->str();
			}

			return result;
		}
};

class Librarian {
	private:
		std::string name;
		int employee_id;

	public:
		Librarian(const std::string& n, int id) : name(n), employee_id(id) {}

		void addBook(std::vector<Book*>& books, Book* book) {
			books.push_back(book);
			std::cout << "Librarian: " << name << " added book " << book->str() << std::endl;
		}

		void removeBook(std::vector<Book*>& books, Book* book) {
			auto it = find(books.begin(), books.end(), book);

			if (it != books.end()) {
				books.erase(it);
				std::cout << "Librarian " << name << " removed book: " << book->str() << std::endl;
			}

			else {
				std::cout << "Book not found in library" << std::endl;
			}
		}

		std::string str() const {
			return "Librarian " + name;
		}
};

class Library {
	private:
		std::vector<Book*> books;
		std::vector<Reader> readers;
		std::vector<Librarian> librarians;

	public:
		void registerReader(const Reader& reader) {
			readers.push_back(reader);
			std::cout << "Registered reader: " << reader.str() << std::endl;
		}

		void addLibrarian(const Librarian& librarian) {
			librarians.push_back(librarian);
			std::cout << "Added librarian: " << librarian.str() << std::endl;
		}

		std::vector<Book*>& getBooks() {
			return books;
		}

		std::vector<Reader> getReaders() const {
			return readers;
		}

		std::vector<Librarian> getLibrarian() const {
			return librarians;
		}
};

int main()
{
	Library lib;
	Librarian lib1("Josh", 1);

	lib.addLibrarian(lib1);
	
	Book* b1 = new EBook("Test1", "test1", "test1", "pdf");
	Book* b2 = new PrintedBook("Test2", "test2", "test2", "printed", 500);
	
	lib1.addBook(lib.getBooks(), b1);
	lib1.addBook(lib.getBooks(), b2);

	lib1.removeBook(lib.getBooks(), b2);

	Reader r1("John", 1);
	lib.registerReader(r1);

	r1.borrowBook(b1);
	std::cout << r1.str() << std::endl;

	r1.returnBook(b1);
	std::cout << r1.str() << std::endl;
}

