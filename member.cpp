#include "member.h"
#include "book.h"
#include <algorithm>
using namespace std;

member::member()
{

}
member::~member()
{

}

vector<int> member::addborrowedbook(vector<book> &books,vector <member> &members, int &bookid, int &memberindex) {
   


        int numborrowed = members.at(memberindex).borrowedbooksIDs.size();

        members.at(memberindex).borrowedbooksIDs.push_back(bookid);
        numborrowed++;
        members.at(memberindex).borrowedbooksIDs.resize(numborrowed);
    
    return members.at(memberindex).borrowedbooksIDs;

}

vector<int> member::returnbook(vector<book>& books, vector <member>& members, int& bookid, int& memberindex) {
	
    int numborrowed = members.at(memberindex).borrowedbooksIDs.size();;

	auto it = find(members.at(memberindex).borrowedbooksIDs.begin(), members.at(memberindex).borrowedbooksIDs.end(), bookid);
	
		if (it != members.at(memberindex).borrowedbooksIDs.end()) {
            members.at(memberindex).borrowedbooksIDs.erase(it);
            numborrowed--;
            members.at(memberindex).borrowedbooksIDs.resize(numborrowed);

        }	

        return borrowedbooksIDs;
}

vector<int> member::viewborrowedbooks(vector<book>& books, vector<member>& members) {

    int memberid;
    member memobj;
    bool memberfound = false;
    bool bookFound = false;

    cout << "enter the member ID:\n";
    cin >> memberid;

    int memberindex = 0;

    for (int i = 0; i < members.size(); i++) {

        if (members.at(i).memID == memberid) {
            memberindex = i;
            memberfound = true;
            break;
        }
     
    }

    if (memberfound) {
        if (members.at(memberindex).borrowedbooksIDs.size() != 0) {
            cout << "this member has borrowed the following:\n";

            for (int j = 0; j < books.size(); j++) {
               
                for (int i = 0; i < members.at(memberindex).borrowedbooksIDs.size(); i++) {
                    if (members.at(memberindex).borrowedbooksIDs.at(i) == books.at(j).ISBN) {
                        bookFound = true;
                        cout << "title: " << books.at(j).title << endl;
                        cout << "author: " << books.at(j).author << endl;
                        cout << "status: ";
                        if (books.at(j).status) {
                            cout << "available\n";
                        }
                        else {
                            cout << "not available\n";
                        }
                        cout << "borrowed date: " << books.at(j).borrowdate.day << "/"
                            << books.at(j).borrowdate.month << "/" << books.at(j).borrowdate.year << endl;
                    }

                }
               
            }
            if (!bookFound) {
                cout << "book was not found in the library.\n";
            }
        }
        else {
            cout << "this member has not borrowed any books.\n";
        }

    }
    else {
        cout << "this member does not exist\n";
    }

   
   
    return borrowedbooksIDs;
}

vector <member> member::registermember(vector<member>& members) {

    member membersobj;
    string name, email;
    int memID, phonenumber;
    int nummembers = members.size();

    cout << "enter member details: " << endl;
    cout << "name:" << endl;
    cin >> membersobj.name;
    cout << "membership ID:" << endl;
    cin >> membersobj.memID;
    cout << "phone number:" << endl;
    cin >> membersobj.contactinfo.phonenumber;
    cout << "email:" << endl;
    cin >> membersobj.contactinfo.email;


    members.push_back(membersobj);
    nummembers++;
    members.resize(nummembers);


    cout << "member registered successfully\n" << endl;

    return members;
}

vector <member> member::updatemember(vector<member>& members) {

	int mid;
	int answer = 0;
	int index = 0;
	int foundindex = 0;
	bool found = false;


	cout << "enter the membership id of the member you'd like to update:" << endl;
	cin >> mid;

	for (auto it = members.begin(); it != members.end(); it++, index++) {

		if (it->memID == mid) {
			foundindex = index;
			found = true;
            cout << "current member details:\n"
                << "ID: " << it->memID << " contact info: " << it->contactinfo.email << " " << it->contactinfo.phonenumber << endl;
		}
	}

	if (found) {
		while (answer != 3) {

			cout << "1. update member email\n"
				<< "2. update member phone number\n"
				<< "3. done\n";

			cin >> answer;

            switch (answer) {

            case 1:
                cout << "enter updated email:\n";
                cin >> members.at(foundindex).contactinfo.email;
                cout << endl;
                break;

            case 2:
                cout << "enter updated phone number:\n";
                cin >> members.at(foundindex).contactinfo.phonenumber;
                cout << endl;
                break;

            case 3:
                cout << endl;
                return members;
                break;
            }
     
		}
	}
    else {
        cout << "this member does not exist" << endl;
    }

	return members;



}
