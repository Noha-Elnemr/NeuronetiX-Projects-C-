#pragma once
#include "user.h"
#include "cart.h"
#include "product.h"
class order
{

public:

	order();
	~order();



	int orderID;
	string shippingDetails = "not out for delivery"; // shipped / not out for delivery
	bool paymentStatus; // true -> paid ,, false -> not paid



	void summary(vector<product> &shoppingCart);
	void confirmOrder();
	void processPayment();

};

