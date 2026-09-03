/*
 * Course: COEN 2220 - Programming 2
 * Name: Logan N. Ramirez Rodriguez
 * Lab: Lab 3 - Object-Oriented Programming, Part 1
 * Description: Guided example - the Book class
 * Due date: 9/3/2026
 */

#include <iostream>
#include <string>
using namespace std;

class Book
{
	private:
		string title;
		string author;
		string isbn;
		bool   isCheckedOut;

	public:
		Book() {
			title = "";
			author = "";
			isbn = "";
			isCheckedOut = false;
		}

		Book(string t, string a, string i) {
			title = t;
			author = a;
			isbn = i;
			isCheckedOut = false;
		}

		string getTitle() const { return title; }
		string getAuthor() const { return author; }
		string getIsbn() const { return isbn; }
		bool   getIsCheckedOut() const { return isCheckedOut; }

		void printInfo() const {
			cout << "Title:  " << title << "\n"
			     << "Author: " << author << "\n"
			     << "ISBN:   " << isbn << "\n"
			     << "Status: " << (isCheckedOut ? "Checked out" : "Available") << "\n";
		}

		void setTitle(string t) {
			if (!t.empty())
				title = t;
		}

		void setAuthor(string a) {
			if (!a.empty())
				author = a;
		}

		void checkOut() {
			if (!isCheckedOut) {
				isCheckedOut = true;
				cout << "\"" << title << "\" is now checked out.\n";
			} else {
				cout << "\"" << title << "\" is already checked out.\n";
			}
		}

		void returnBook() {
			if (isCheckedOut) {
				isCheckedOut = false;
				cout << "\"" << title << "\" has been returned.\n";
			} else {
				cout << "\"" << title << "\" was not checked out.\n";
			}
		}
};

int main() {
	Book b1("Clean Code", "Robert C. Martin", "978-0132350884");

	cout << "--- Initial state ---\n";
	b1.printInfo();

	cout << "\n--- After setTitle/setAuthor ---\n";
	b1.setTitle("Clean Code (2nd Edition)");
	b1.setAuthor("");
	b1.printInfo();

	cout << "\n--- Checking out ---\n";
	b1.checkOut();
	b1.checkOut();

	cout << "\n--- Returning ---\n";
	b1.returnBook();
	b1.returnBook();

	return 0;
}