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
		// Everything a Book needs to "know" about itself.
		// All private: nothing outside this class can touch these
		// directly - that's the point of encapsulation.
		string title;
		string author;
		string isbn;
		bool   isCheckedOut;

	public:
		// --- STEP 1: constructors + getters ---

		// Default constructor: runs automatically when you write
		// `Book b;` with no arguments. Strings default to "" on their
		// own, but isCheckedOut (a bool) would start as unpredictable
		// garbage without this - so we set it explicitly to false.
		Book() {
			title = "";
			author = "";
			isbn = "";
			isCheckedOut = false;
		}

		// Parameterized constructor: lets us create a fully-formed
		// Book in one line, instead of creating an empty one and then
		// calling setters one at a time. This is the one we'll
		// actually use in main() below.
		Book(string t, string a, string i) {
			title = t;
			author = a;
			isbn = i;
			isCheckedOut = false;   // a brand-new book always starts available
		}

		// Getters: marked const because reading a value should never
		// change the object. The compiler enforces this - if you
		// accidentally wrote code in here that modified a member, it
		// wouldn't compile.
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

		// --- STEP 2: setters (uncomment the /* ... */ block below when instructed) ---
		void setTitle(string t) {
			if (!t.empty())
				title = t;
		}

		void setAuthor(string a) {
			if (!a.empty())
				author = a;
		}

		// --- STEP 3: behavior (uncomment the /* ... */ block below when instructed) ---
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
	// Using the parameterized constructor - real-looking but dummy data.
	Book b1("Clean Code", "Robert C. Martin", "978-0132350884");

	cout << "--- Initial state ---\n";
	b1.printInfo();

	cout << "\n--- After setTitle/setAuthor ---\n";
	b1.setTitle("Clean Code (2nd Edition)");
	b1.setAuthor("");   // empty string - should be REJECTED
	b1.printInfo();

	cout << "\n--- Checking out ---\n";
	b1.checkOut();
	b1.checkOut();   // try again - should say it's already out

	cout << "\n--- Returning ---\n";
	b1.returnBook();
	b1.returnBook(); // try again - should say it wasn't out

	return 0;
}