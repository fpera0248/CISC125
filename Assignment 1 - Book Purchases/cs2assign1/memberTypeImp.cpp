
#include <iostream>
#include <string>
#include "memberType.h"

using namespace std;

void memberType::setMemberInfo(string ID, string fName,
	string lName, int bPurchased,
	double amount)
{
	memberID = ID;
	firstName = fName;
	lastName = lName;
	numBooks = bPurchased;
	purchaseAmt = amount;

	// Accessor function

}

void memberType::setMemberID(string ID)
{
	memberID = ID;
}

void memberType::setName(string fName, string lName)
{
	firstName = fName;
	lastName = lName;

}

bool memberType::isMemberID(string ID) const
{
	return (memberID == ID);
}
//need this

int memberType::getBooksPurchased() const
{
	return numBooks;
}
//need this

double memberType::getTotalAmountSpent() const
{
	return purchaseAmt;
}
//need this

void memberType::addNewPurchase(double amount)
{
	numBooks++;
	purchaseAmt = purchaseAmt + amount;
}
//needthis

void memberType::resetbooksBoughtAndAmount()
{

	numBooks = 0;
	purchaseAmt = 0;
}
//needthis

void memberType::printMemberID() const
{
	cout << "Member ID: " << memberID << endl;
}

void memberType::printName() const
{
	cout << "Name: " << firstName << " " << lastName << endl;
}

void memberType::printInfo() const
{
	cout << "Member ID: " << memberID << endl;
	cout << "Name: " << firstName << " " << lastName << endl;
	cout << "Number of Books Bought: " << numBooks << endl;
	cout << "Total Amount Spent: " << purchaseAmt << endl;
}

memberType::memberType() {
	//empty defautl constructor 
}

memberType::memberType(string memberName, string memberID)
{
	//left id, name, and books, and amount blank and amount to zero. 
	memberID = "";
	firstName = "";
	lastName = "";
	numBooks = 0;
	purchaseAmt = 0;
	//This is the contructor part of the homework
	//Make sure it is ready to accept values from the input file
}

