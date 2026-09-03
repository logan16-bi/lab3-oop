/*
 * Course: COEN 2220 - Programming 2
 * Name: Logan N. Ramirez Rodriguez
 * Lab: Lab 3 - Object-Oriented Programming, Part 1
 * Description: Converting a struct to a class with encapsulation
 * Due date: 9/3/2026
 */

#include <iostream>
using namespace std;

struct RectangleStruct
{
	double width;
	double height;
};

class RectangleClass
{
	private:
		double width;
		double height;

	public:
		RectangleClass() {
			width = 0.0;
			height = 0.0;
		}

		void setWidth(double w) {
			if (w > 0)
				width = w;
		}

		void setHeight(double h) {
			if (h > 0)
				height = h;
		}

		double getWidth() const { return width; }
		double getHeight() const { return height; }
		double getArea() const { return width * height; }
};
  
int main() {
	RectangleStruct r;
	r.width = -5.0;
	r.height = 3.0;
	cout << "Struct area (con ancho invalido): " << (r.width * r.height) << endl;

	RectangleClass rc;
	rc.setWidth(4.0);
	rc.setHeight(3.0);
	cout << "Class area (valid data): " << rc.getArea() << endl;

	rc.setWidth(-10.0);
	cout << "Class area (after invalid setWidth attempt): " << rc.getArea() << endl;

	return 0;
}
