#include <iostream>
#include "cart.h"
#include "order.h"
#include "user.h"
#include "product.h"
#include <vector>
#include <iomanip>

using namespace std;

//vectors declaration
vector <product> products;
vector <product> shoppingCart;


//object 

order ord;
user usr;
cart crt;
product prod;


void menu() {

	float totalPrice = 0.0;
	int choiceNumber = 0;

	while (choiceNumber != 8) {

		cout << setw(10) << "1. browse products\n"
			<< setw(10) << "2. search and filter products\n"
			<< setw(10) << "3. add items to cart\n"
			<< setw(10) << "4. remove items from cart\n"
			<< setw(10) << "5. view cart\n"
			<< setw(10) << "6. order summary\n"
			<< setw(10) << "7. confirm order\n"
			<< setw(5) << "8. exit" << endl;

		cin >> choiceNumber;

		switch (choiceNumber) {
		case 1:
			prod.browse(products);
			break;

		case 2:
			prod.search(products);
			break;

		case 3:
			shoppingCart = crt.add(products);
			break;

		case 4:
			crt.remove(shoppingCart);
			break;

		case 5:
			totalPrice = crt.view(shoppingCart);
			break;

		case 6:
			ord.summary(shoppingCart);
			crt.applyDiscount(totalPrice);
			break;

		case 7:
			ord.confirmOrder();
			break;

		case 8:
			exit(1);
			break;

		default:
			cout << "please choose a valid option (1-8)" << endl;
			break;
		}

	}
}

int main() {

	products = { product("redbull", "energy drink", "drink", 40, 5), product("vcola", "soda", "drink", 20, 10)};

	user usr1("lol", 010, "neuro@gmail.com", "cairo", "aaa", 20, 7, 77);

	menu();

	return 0;

}