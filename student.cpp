/*
 * Course: COEN 2220 - Programming 2
 * Name: Logan N. Ramirez Rodriguez
 * Lab: Lab 3 - Object-Oriented Programming, Part 1
 * Description: Student class - exercise with TODOs
 * Due date: 9/3/2026
 */

#include <iostream>
#include <string>
using namespace std;

class Student
{
	private:
		string name;
		int    id;
		double gpa;

	public:
		Student() {
			name = "";
			id = 0;
			gpa = 0.0;
		}

		Student(string n, int i, double g) {
			name = n;
			id = i;
			setGpa(g);
		}

		void setName(string n) {
			if (!n.empty())
				name = n;
		}

		void setGpa(double g) {
			if (g >= 0.0 && g <= 4.0)
				gpa = g;
			else
				cout << "Invalid GPA: " << g << " (must be between 0.0 and 4.0)\n";
		}

		string getName() const { return name; }
		int    getId() const { return id; }
		double getGpa() const { return gpa; }

		void printInfo() const {
			cout << "Name: " << name << "\n"
			     << "ID:   " << id << "\n"
			     << "GPA:  " << gpa << "\n";
		}

		// TODO (Parte E): Destructor.
		// Print a message indicating that the Student object with that 'name' was destroyed.
};

int main() {
	Student s1;
	s1.setName("John Doe");
	s1.setGpa(0.0);
	s1.printInfo();

	cout << "\n";
	s1.setGpa(5.0);

	cout << "\n";
	Student s2("Alice Smith", 1001, 3.7);
	s2.printInfo();

	return 0;
}