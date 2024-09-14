#pragma once
#include <chrono>
#include <iostream>
#include "member.h"
#include "library.h"

using namespace std;
using namespace chrono;
class book
{


public:

	book();
	~book();

	string title;
	string author;
	int ISBN;
	int borrowedby;

	struct Date {
		int year = 0;
		int month = 0;
		int day = 0;
	} pubdate, borrowdate, returndate;


	bool status;  // ( true == available, false == checked out )

	Date getdate();
	void borrowbooks(vector<book>& books, vector<member>& members);
	void returnbook(vector<book>& books, vector <member>& members);
	vector<book> deletebook(vector<book>& books);
	vector<book> addbooks(vector<book>& books);
	vector <book> updatebook(vector<book>& books);

};

