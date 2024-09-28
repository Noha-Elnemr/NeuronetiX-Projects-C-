#include "product.h"
#include <iostream>
#include <vector>
using namespace std;

product::product()
{

}

product::product(string pname, string pdescription, string pcategory, int pprice, int pquantity) {
	name = pname;
	description = pdescription;
	category = pcategory;
	price = pprice;
	quantity = pquantity;
	productsExisting++;
}


product::~product()
{

}


void product::browse(vector<product>& products) {

	for (int i = 0; i < products.size(); i++) {

		cout << "product name:" << endl;
		cout << products[i].name << endl;

		cout << "description:" << endl;
		cout << products[i].description << endl;

		cout << "category:" << endl;
		cout << products[i].category << endl;

		cout << "price:" << endl;
		cout << products[i].price << endl;

		cout << "quantity available:" << endl;
		cout << products[i].quantity << endl;

		cout << endl;

	}
}


void product::search(vector<product>& products) {

	string filter;

	cout << "filter by name / category" << endl;
	cout << "type ""name"" or ""category""" << endl;
	cin >> filter;

	if (filter == "name") {
		string filterName;
		cout << "enter the name of the product:" << endl;
		cin >> filterName;

		for (auto it = products.begin(); it != products.end(); it++) {

			if (it->name == filterName) {

				cout << "name:" << endl;
				cout << it->name;

				cout << "description:" << endl;
				cout << it->description << endl;

				cout << "category:" << endl;
				cout << it->category << endl;

				cout << "price:" << endl;
				cout << it->price << endl;

				cout << "quantity:" << endl;
				cout << it->quantity << endl;

				cout << endl;

			}

		}
	}
	else if (filter == "category") {
		string filterCategory;
		cout << "enter the category of the product:" << endl;
		cin >> filterCategory;

		for (auto it = products.begin(); it != products.end(); it++) {

			if (it->category == filterCategory) {

				cout << "name:" << endl;
				cout << it->name;

				cout << "description:" << endl;
				cout << it->description << endl;

				cout << "category:" << endl;
				cout << it->category << endl;

				cout << "price:" << endl;
				cout << it->price << endl;

				cout << "quantity:" << endl;
				cout << it->quantity << endl;

				cout << endl;

			}

		}

	}

}

