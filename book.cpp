#include "book.h"
#include "member.h"
#include <string>

book::book()
{

}
book::~book()
{

}

book::Date book::getdate() {
	auto now = system_clock::now();

	// Convert to time_t to get calendar time
	auto now_c = system_clock::to_time_t(now);

	// Create a tm structure to store the broken-down time
	tm now_tm;

	// Use localtime_s without explicit error checking
	localtime_s(&now_tm, &now_c);

	// Create a Date instance and populate it
	Date date;
	date.day = now_tm.tm_mday;
	date.month = now_tm.tm_mon;  // tm_mon is 0-based, so add 1
	date.year = now_tm.tm_year;  // tm_year is years since 1900

	return date;

}


vector<book> book::addbooks(vector<book>& books) {
	string title, author;
	int ISBN, year, month, day;
	library librrrary;
	book bookobject;

	int numbooks = books.size();

	cout << "enter book details: " << endl;
	cin.ignore();
	cout << "title:\n";
	getline(cin, bookobject.title);
	cout << "author:\n";
	getline(cin, bookobject.author);
	cout << "ISBN:\n";
	cin >> bookobject.ISBN;
	cout << "publication date:\n";
	cout << "day // month // year:\n";
	cin >> bookobject.pubdate.day >> bookobject.pubdate.month >> bookobject.pubdate.year;
	cout << endl;
	bookobject.borrowedby = 0;

	books.push_back(bookobject);
	numbooks++;
	books.resize(numbooks);

	return books;
}

vector<book> book::deletebook(vector<book>& books) {

	int isbndel;
	bool found = false;

	cout << "enter the isbn of the book you would like to remove:" << endl;
	cin >> isbndel;

	for (auto it = books.begin(); it != books.end(); it++) {

		if (it->ISBN == isbndel) {
			found = true;
			books.erase(it);
			cout << "book with ISBN" << isbndel << " has been deleted" << endl;
			break;
		}

	}

	if (!found) {
		cout << "book with ISBN: " << isbndel << " was not found" << endl;
	}

	return books;
}


vector <book> book::updatebook(vector<book>& books) {

	int bkid;
	int answer = 0;
	int index = 0;
	int foundindex = 0;
	bool found = false;

	//book updatedbook;

	cout << "enter the ISBN of the book you'd like to update:" << endl;
	cin >> bkid;

	for (auto it = books.begin(); it != books.end(); it++, index++) {

		if (it->ISBN == bkid) {
			foundindex = index;
			found = true;
			cout << "current book details:\n"
				<< "title: " << it->title << "\nauthor: " << it->author << "\npublication date: " << it->pubdate.day << "/" << it->pubdate.month << "/" << it->pubdate.year << endl;;
			cout << "\nstatus: ";
			if (it->status) {
				cout << "available\n\n";
			}
			else {
				cout << "not available\n\n";
			}
		}
		
	}
	
	if (!found) {

		cout << "this book does not exist.\n";
		return books;
	}

	if (found) {
		while (answer != 5) {

			cout << "1. update book title\n"
				<< "2. update book author\n"
				<< "3. update book publication date\n"
				<< "4. update book status\n"
				<< "5. done\n";

			cin >> answer;

			switch (answer) {

			case 1:
				cout << "enter updated book title:\n";
				cin >> books.at(foundindex).title;
				break;

			case 2:
				cout << "enter updated book author:\n";
				cin >> books.at(foundindex).author;
				break;

			case 3:
				cout << "enter updated book publication date:\n";
				cin >> books.at(foundindex).pubdate.day >> books.at(foundindex).pubdate.month >> books.at(foundindex).pubdate.year;
				break;
			
			case 4:
				char updatedstatus;
				cout << "updated book status: (y for available , else for not available )\n";
				cin >> updatedstatus;

				if (updatedstatus == 'y') {
					books.at(foundindex).status = true;
				}
				else books.at(foundindex).status = false;

				break;

			case 5: 
				return books;
				break;
			}

		}
	}
	cout << endl;

	return books;
}


void book::borrowbooks(vector<book>& books, vector<member>& members) {

	Date borroweddate;

	int index = 0;

	bool memberfound = false;
	bool bookfound = false;

	int isbnborrow, membid;
	cout << " enter the ISBN of the book being borrowed: " << endl;
	cin >> isbnborrow;

	for (auto it = books.begin(); it != books.end(); it++) {

		if (it->ISBN == isbnborrow) {

			bookfound = true;

			if (it->status == false) {

				cout << "this book is not available" << endl;
			}

			else {
				cout << "the book details are: " << endl;
				cout << it->title << " " << it->author << " " << it->ISBN << " ";
				if (it->status) {
					cout << "available\n";
				}
				else cout << "not available\n";

				cout << "enter the membership ID of the member borrowing the book:" << endl;
				cin >> membid;

				for (auto its = members.begin(); its != members.end(); its++,index++) {

					if (its->memID == membid) {
						int memberindex = index;
						memberfound = true;

						its->addborrowedbook(books, members, isbnborrow,memberindex);
						it->status = false;
						it->borrowedby = its->memID;

						borroweddate = getdate();

						it->borrowdate.day = borroweddate.day;
						it->borrowdate.month = borroweddate.month;
						it->borrowdate.year = borroweddate.year + 1900;

						it->returndate.day = 00;
						it->returndate.month = 00;
						it->returndate.year = 00;

						cout << "the book has been successfully borrowed\n";

						break;

					}
					
				}

				if (!memberfound) {
					cout << "member does not exist" << endl;
				}
			}
		}

	}
		if (!bookfound) {
			cout << "book does not exist" << endl;
		}


}

void book::returnbook(vector<book>& books, vector <member>& members) {

	Date returneddate;
	int isbnreturn;
	bool found = false;
	bool borrowed = false;

	int index = 0;

	cout << "enter the isbn of the book being returned:" << endl;
	cin >> isbnreturn;

	for (auto it = books.begin(); it != books.end(); it++) {

		if (it->ISBN == isbnreturn) {
			found = true;

			if (it->status == false) {
				borrowed = true;
				cout << "the returned books details are: " << endl;
				cout << it->title << " " << it->author << " " << it->ISBN << endl;


				for (auto its = members.begin(); its != members.end(); its++,index++) {

					if (it->borrowedby == its->memID) {
						int memberindex = index;
						it->status = true;
						it->borrowedby = 0;
						returneddate = getdate();

						it->returndate.day = returneddate.day;
						it->returndate.month = returneddate.month;
						it->returndate.year = returneddate.year + 1900;

						it->borrowdate.day = 00;
						it->borrowdate.month = 00;
						it->borrowdate.year = 00;

						its->returnbook(books,members, isbnreturn,memberindex);
						
						cout << "the book has been successfully returned\n";

						break;
					}

				}

			}

		}

	}

		if (!found) {
			cout << "book was not found" << endl;
		}
		if (found && !borrowed) {
			cout << "book was not borrowed" << endl;
		}


}