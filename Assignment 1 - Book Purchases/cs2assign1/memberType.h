#pragma once

#include <string>
using namespace std;

class memberType
{
public:
	void setMemberInfo(string ID, string fName, string lName,
		int bPurchased, double amount);
	void setMemberID(string);
	void setName(string, string);

	bool isMemberID(string) const;

	int getBooksPurchased() const;
	double getTotalAmountSpent() const;

	void addNewPurchase(double amount);

	void resetbooksBoughtAndAmount();

	void printMemberID() const;
	void printName() const;

	void printInfo() const;

	memberType();
	memberType(string memberName, string memberID);

private:
	string memberID;
	string firstName;
	string lastName;

	int numBooks;
	double purchaseAmt;
};
