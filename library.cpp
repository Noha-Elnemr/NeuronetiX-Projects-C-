#include "library.h"
#include "book.h"
#include "member.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;
using namespace chrono;


library::library()
{

}
library::~library()
{

}


void library::viewallbooks(vector<book> &books) {

	for (auto it = books.begin(); it != books.end(); it++) {

		cout << "title: " << it->title << endl;
		cout << "author: " << it->author << endl;
		cout << "ISBN: " << it->ISBN << endl;
		cout << "status: ";
			if (it->status) {
				cout << "available\n";
			}
			else {
				cout << "not available\n";
				cout << "borrowed by: ( memID ) " << it->borrowedby << endl;
			
			}
		

		if (it->status == false) {   // not avail
			cout << "borrowed on\n";
			cout << it->borrowdate.day << "/" << it->borrowdate.month << "/" << it->borrowdate.year << endl;

		}
		if (it->returndate.year != 00){  // available fa wareny kan returned emta
			cout << "returned on\n";
			cout << it->returndate.day << "/" << it->returndate.month << "/" << it->returndate.year << endl;
		}
	}
}

void library::viewallmembers(vector<member>& members) {

	for (auto it = members.begin(); it != members.end(); it++) {

		cout << "name: " << it->name << endl;
		cout << "ID: " << it->memID << endl;
		cout << "email: " << it->contactinfo.email << endl;
		cout << "phone number: " << it->contactinfo.phonenumber << endl;
		cout << endl;
	}
		cout << endl;
}