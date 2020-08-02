// This program demonstrates the Account Class
#include <iostream>
#include <cctype>
#include <iomanip>
#include "account.h"
using namespace std;

// Function Prototyopes
void displayMenu();
void makeDeposit(account &);
void makeWithdrawal(account &);
int main()
{
	account checking;
	char choice;

	cout << fixed << showpoint << setprecision(2);

	do
	{
		displayMenu();
		cin >> choice;
		while (toupper(choice) < 'A' || toupper(choice) > 'G')
		{
			cout << "Please make a choice in the range of A through G shithead: ";
			cin >> choice;
		}

		switch (choice)
		{
		case 'a':
		case 'A':
			cout << "The current balance is $";
			cout << checking.getBalance() << endl;
			break;
		case 'b':
		case 'B':
			cout << "There have been ";
			cout << checking.getTransactions() << " transactions.\n";
			break;
		case 'c':
		case 'C':
			cout << "Interest earned for this period: $";
			cout << checking.getInterest() << endl;
			break;
		case 'd':
		case 'D':
			makeDeposit(checking);
			break;
		case 'e':
		case 'E':
			makeWithdrawal(checking);
			break;
		case 'f':
		case 'F':
			checking.calcInterest();
			cout << "Interest added.\n";
		}
	} while (toupper(choice) != 'G');

	return 0;
}

void displayMenu()
{
	cout << "\n				MENU				\n";
	cout << "-----------------------------------\n";
	cout << "A) Display the account balance\n";
	cout << "B) Display the number of transactions\n";
	cout << "C) Display intgerest earned for this period\n";
	cout << "D) Make a Deposit\n";
	cout << "E) Make a Withdrawal\n";
	cout << "F) Add interest for this period\n";
	cout << "G) Exit the program\n\n";
	cout << "Enter your choice: ";
}

void makeDeposit(account &acnt)
{
	double addition;
	cout << "Enter the amount of the deposit: ";
	cin >> addition;
	cin.ignore();
	acnt.makeDeposit(addition);
	cout << acnt.getBalance() << endl;
}

void makeWithdrawal(account &acnt)
{
	double subtraction;
	cout << "Enter the amount of the withdrawal: ";
	cin >> subtraction;
	cin.ignore();
	acnt.makeWithdrawal(subtraction);
	cout << acnt.getBalance() << endl;
}