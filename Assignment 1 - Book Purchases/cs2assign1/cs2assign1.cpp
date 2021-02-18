// Fernando Peralta
// CISC 125 - Monday's from 1:00 pm - 2:50 pm 
// Assignment 1 due Sunday February 14th
// This program is made to create a memberType object and then call an addNewPurchase function twice( Representing 2 new purchases)
// I coded the function to run for as many times as the user wanted. The user can make a purchase for any memberID and after all of the purchase are done, the file is outputted.

#include <iostream>
#include <string>
#include <fstream>
#include "memberType.h" 
//#include "memberTypeImp.cpp"


using namespace std;

void getMembersData(memberType members[], int& count);
void printMembersData(memberType members[], int count);

int main()
{
	memberType storeMembers[500];
	int numberOfMembers = 0;

	getMembersData(storeMembers, numberOfMembers);

	numberOfMembers++;                                                    //added this to add myself as a new member to the array
	storeMembers[4].setMemberInfo("50", "Fernando", "Peralta", 0, 0);
	storeMembers[4].addNewPurchase(95.45); // These are 2 purchases that are made by me and showed when the printMembersData function is called
	storeMembers[4].addNewPurchase(49.99);

	printMembersData(storeMembers, numberOfMembers);

	bool searchloop;  // This is a do while loop that acquires the user's input and locates the memberID that wants to purchase a book
	do {
		string searchid;
		double price;
		cout << "Enter the member ID that wants to buy a book: Choose between member ID's 10, 20, 30, 40 and 50 \n";
		cin >> searchid;
		int location = 0;
		for (int i = 0; i < 500; i++) { // This for loop searches the entire array for the inputted ID number
			if (storeMembers[i].isMemberID(searchid)) {
				location = i;
				//cout << "\n" <<location << endl; debugging
				break;
			}
		}
		bool purchaseloop; // This do while loop adds the price to the addNewPurchase function and calculates the total price of all of the books
		do {
			cout << "Enter Price of book: \n";
			cin >> price;
			storeMembers[location].addNewPurchase(price);
			cout << "Enter 1 to Purchase another book, enter 0 to exit" << endl;
			cin >> purchaseloop;
		} while (purchaseloop == 1);

		cout << "Enter 1 to search for member id, enter 0 to exit" << endl;
		cin >> searchloop;
	} while (searchloop == 1);
	printMembersData(storeMembers, numberOfMembers);   //nmoved here
	return 0;
}

void getMembersData(memberType members[], int& count)
{
	int i;

	string ID;
	string fName;
	string lName;
	int bookCount;
	double amount;

	ifstream infile;

	infile.open("memberData.txt");

	infile >> count;

	for (i = 0; i < count; i++)
	{
		infile >> ID >> fName >> lName >> bookCount >> amount;
		members[i].setMemberInfo(ID, fName, lName, bookCount, amount);
	}
}

void printMembersData(memberType members[], int count)
{
	int i;

	for (i = 0; i < count; i++)
		members[i].printInfo();
}

