#pragma once
#include "cart.h"
#include "product.h"
#include "order.h"
#include <iostream>
#include <vector>
class user
{
public:

	//cart userCart;
	user();
	user(string name, int phone, string email, string city, string streetName, int buildingNo, int floorNo, int apartmentNo);
	~user();

	string name;
	//void setContact(string name);
	//void setContact(int phone, string email);
	//void setAddress(string city, string streetName, int buildingNo, int floorNo, int apartmentNo);


	void viewCart(vector<product>&shoppingCart);

private:

	//vector<product> userCart;


	struct contact {
		int phoneNumber;
		string email;
	} contactInformation;

	struct address {
		string city;
		string streetName;
		int buildingNumber;
		int floorNumber;
		int apartmentNumber;
	} shippingAddress;



};

