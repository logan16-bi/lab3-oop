/*
 * Course: COEN 2220 - Programming 2
 * Name: Logan N. Ramirez Rodriguez
 * Lab: Lab 3 - Object-Oriented Programming, Part 1
 * Description: Class skeletons - restaurant case design
 * Due date: 9/3/2026
 */

#include <iostream>
#include <string>
using namespace std;

// Reminder of the scenario (see "Contexto" above for the full version):
// "A restaurant takes orders from tables. Each order has a list of
//  dishes, each with a name and a price. At the end, the restaurant
//  calculates the order total, including a 10% service charge."

class Dish
{
	private:
		string name;
		double price;

	public:
		Dish();
		Dish(string n, double p);
		string getName() const;
		double getPrice() const;
};

class Order
{
	private:
		Dish dishes[20];
		int  dishCount;
		int  tableNumber;

	public:
		Order();
		Order(int table);
		void addDish(Dish d);
		double getTotal() const;
};

// I put the 10% charge in Order because each order should be able to
// calculate its own total by itself, without needing Restaurant.

int main() {
	cout << "Esqueletos de diseno - sin logica de ejecucion en este bloque.\n";
	return 0;
}