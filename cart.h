#pragma once
#include "product.h"
#include "user.h"
class cart
{

public:



	cart();
	~cart();

	int cartSize;

	vector<product> add(vector<product>& products);
	void remove(vector <product>& shoppingCart);
	float view(vector <product>& shoppingCart);
	void applyDiscount(float &totalPrice);

	vector <product> shoppingCart;


};

