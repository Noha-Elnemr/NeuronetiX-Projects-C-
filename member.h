#pragma once
#include <iostream>
#include <vector>
#include <chrono>
#include "book.h"
#include "library.h"

using namespace std;
using namespace chrono;

class book;
class member
{
public:
	string name;
	int memID;

	struct contact {
		int phonenumber;
		string email;
	} contactinfo;

	vector<int> borrowedbooksIDs;

	member();
	~member();
	vector<int> addborrowedbook(vector<book> &books,vector <member> &members,int &bookid, int&memberindex);
	vector <int> returnbook(vector<book>& books, vector <member>& members, int& bookid, int& memberindex);
	vector<int> viewborrowedbooks(vector<book>& books, vector<member> &members);
	vector <member> registermember(vector<member>& members);
	vector <member> updatemember(vector<member>& members);

};

