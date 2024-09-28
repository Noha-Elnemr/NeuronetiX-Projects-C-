#include "cart.h"
#include "product.h"
#include "user.h"
#include <iostream>
#include <vector>
using namespace std;

cart::cart()
{

}
cart::~cart()
{

}


vector <product> cart::add(vector<product>& products) {

	string productName;
	int itemsNeeded;

	cartSize = shoppingCart.size();

	cout << "enter the name of the product you would like to add:" << endl;
	cin >> productName;


	for (auto it = products.begin(); it != products.end(); it++) {

		if (it->name == productName) {

			cout << "available quantity is:" << endl;
			cout << it->quantity << endl;

			cout << "enter the amount you want:" << endl;
			cin >> itemsNeeded;
			cout << endl;

			it->quantity-= itemsNeeded;

			shoppingCart.push_back(*it);
			cartSize++;
			shoppingCart.resize(cartSize);
			shoppingCart[cartSize - 1].quantity = itemsNeeded;

		}

	}

	return shoppingCart;
}

void cart::remove(vector <product>& shoppingCart) {

	string productName;

	cartSize = shoppingCart.size();

	cout << "enter the name of the product you would like to remove:" << endl;
	cin >> productName;

	for (auto it = shoppingCart.begin(); it != shoppingCart.end(); it++) {

		if (it->name == productName) {

			shoppingCart.erase(it);
			break;
		}

	}
}

float cart::view(vector <product>& shoppingCart) {


	float totalPrice = 0;
		for (auto it = shoppingCart.begin(); it != shoppingCart.end(); it++) {

			cout << "name:" << endl;
			cout << it->name << endl;

			cout << "description:" << endl;
			cout << it->description << endl;

			cout << "category:" << endl;
			cout << it->category << endl;

			cout << "price:" << endl;
			cout << it->price << endl;

			cout << "quantity:" << endl;
			cout << it->quantity << endl;

			cout << endl;

			totalPrice += it->price * it->quantity;
		}
			
		return totalPrice;

}

void cart::applyDiscount(float &totalPrice) {

	string promoCode;

	cout << "\nenter promo code: (type " "none" " if no promo codes) " << endl;
	cin >> promoCode;

	if (promoCode == "neuro") {

		cout << "10% discount applied !!" << endl;
		totalPrice -= (totalPrice * 0.10);

	}

	cout << "total price:" << endl;
	cout << totalPrice << endl;

}


