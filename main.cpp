#include <iostream>
#include <chrono>
#include <iomanip>
#include "book.h"
#include "member.h"
#include "library.h"

using namespace std;
using namespace chrono;

//vectors declaration
vector <int> borrowedbooks;
vector <book> bookss;
vector <member> memberss;

//object 
library lib;
member mem;
book bok;


void menu() {

	
	int ans = 0;

	while (ans!=11) {

		cout << setw(10) << "1. register a member\n"
			<< setw(10) << "2. update a members info\n"
			<< setw(10) << "3. add a book\n"
			<< setw(10) << "4. delete a book\n"
			<< setw(10) << "5. update a book\n"
			<< setw(10) << "6. borrow a book\n"
			<< setw(10) << "7. return a book\n"
			<< setw(10) << "8. view all books\n"
			<< setw(10) << "9. view all members\n"
			<< setw(9) << "10. view members borrowed books\n"
			<< setw(8) << "11. exit" << endl;

		cin >> ans;

		switch (ans) {
		case 1:
			mem.registermember(memberss);
			break;

		case 2:
			mem.updatemember(memberss);
			break;

		case 3:
			bok.addbooks(bookss);
			break;

		case 4:
			bok.deletebook(bookss);
			break;

		case 5: 
			bok.updatebook(bookss);
			break;

		case 6:
			bok.borrowbooks(bookss, memberss);
			break;

		case 7:
			bok.returnbook(bookss, memberss);
			break;

		case 8:
			lib.viewallbooks(bookss);
			break;

		case 9:
			lib.viewallmembers(memberss);
			break;

		case 10: 
			mem.viewborrowedbooks(bookss, memberss);
			break;

		case 11:
			exit(1);
			break;

		default:
			cout << "please choose a valid option (1-10)" << endl;
			break;
		}

	}
}

int main() {

	menu();

	return 0;

}