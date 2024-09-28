#pragma once
#include <vector>
#include <string>
#include <iostream>
using namespace std;

class product
{
public:

	product();
	product(string pname, string pdescription, string pcategory, int pprice, int pquantity);
	~product();

	string name;
	string description;
	string category;
	int price;
	int quantity;
	int productsExisting = 0;
	//int itemsNeeded;

	//vector<product> create(vector<product> &products);

	void browse(vector<product>& products);
	void search(vector<product>& products);


};

