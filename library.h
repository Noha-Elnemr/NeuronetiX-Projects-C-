#pragma once
#include <iostream>
#include "book.h"
#include "member.h"
using namespace std;
class book;
class member;
class library
{
public:
	struct Date {
		int day = 0;
		int month = 0;
		int year = 0;
	};

	library();
	~library();

	void viewallbooks(vector<book> &books);
	void viewallmembers(vector<member>& members);

};

