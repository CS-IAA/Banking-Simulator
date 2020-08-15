#include "Bank.h"
#include <iostream>
#include <cstdlib>
#include <string>
#include <iomanip>

using namespace std;

// constructor(class function)
Bank::Bank()
{
    accountNumber = 9999;
    name = "";
    balance = 0;
    accountType = "";
}
// constructor(class function)
Bank::Bank(int aN, string n, double b, string t)
{
    accountNumber = aN;
    name = n;
    balance = b;
    accountType = t;
}

//mutator function that withdraws money from bank acc
string Bank::withdraw(double amount)
{
    string bal;

    if (balance >= amount)
    {
        balance -= amount;
        bal = to_string(balance);
    }
    else
    {
        bal = "Insufficient balance";
    }

    return bal;
}

//mutator function that adds money to bank acc
double Bank::deposit(double amount)
{
    balance += amount;

    return balance;
}

// savings construction function
Savings::Savings():Bank()
{
    interestRate = 0;
    compoundPeriod = 0;
}

// savings construction function
Savings::Savings(double iR, int p, int aN, string n, double b, string t):Bank(aN, n, b, t)
{
    interestRate = iR;
    compoundPeriod = p;
}

//mutator function that adds interest to bank acc
double Savings::addInterest()
{
    double interestDays;

    interestDays = balance * interestRate * (compoundPeriod/365);

    balance += interestDays;

    return balance;
}


// checking construction bank
Checking::Checking():Bank()
{
    minBalance = 0;
    monFee = 0;
}

// checking construction bank
Checking::Checking(double ba, double f, int aN, string n, double b, string t):Bank(aN, n, b, t)
{
    minBalance = ba;
    monFee = f;
}

//mutator function that adds fee to bank acc
double Checking::chargeFee()
{
    balance -= monFee;

    if (balance < 0)
    {
        balance = 0;
    }

    return balance;
}

// stand alone function that displays bank info
void displayAccountInfo(Bank bank)
{
    cout << "Account Information" << endl;
    cout << "Account Number: " << bank.getAccountNumber() << endl; // get info from bank class
    cout << "Name: " << bank.getName() << endl;
    cout << "Balance: $" << setprecision(2) << fixed << bank.getBalance() << endl;
    cout << "Account Type: " << bank.getType() << endl;
}
