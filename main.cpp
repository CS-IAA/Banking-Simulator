/*
Banking Simulator Program

A C++ program that provides the user with 8 choices.
It allocates functions, classes, .cpp, and .h files for this. Pointer to objects is used specifically.
Creates savings account, creates checking account, creaks bank object with no parameters, deposits money to bank account, withdraws money from bank account,
displays info of all bank accounts, applies interest to savings, or charge fee for checking.
Error checks.

Ismail Ahmed
UT Dallas - CS 1337.004
*/

// preprocessor directives
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <cstdlib>
#include <cmath>
#include "Bank.h"
#include "Bank.cpp"

using namespace std;

// function prototypes
void createSavings(Bank *Account[], int&);
void createChecking(Bank *Account[], int&);
void createBank(Bank *Account[], int&);
void depositBank(Bank *Account[], int&);
void withdrawBank(Bank *Account[], int&);
void displayBank(Bank *Account[], int&);
void scBank(Bank *Account[], int&);

// initialize main funtion
int main()
{
    // local variables
    const int SIZE = 100;
    int choice;
    int aIndex = 0;

    Bank *Account[SIZE]; // pointer to object

    while(true) // infinite loop
    {
        // menu display
        cout << "1. Create a Savings object with values for accountNumber, name, and balance." << endl;
        cout << "2. Create a Checking object with values for accountNumber, name, and balance" << endl;
        cout << "3. Create Bank object with no parameters." << endl;
        cout << "4. Deposit to Bank account." << endl;
        cout << "5. Withdraw from Bank account." << endl;
        cout << "6. Display information for all accounts including information that is specific to either checking or savings accounts." << endl;
        cout << "7. Apply interest to savings, or charge fee for checking." << endl;
        cout << "8. Exit the program." << endl;

        cout << "My choice: ";
        cin >> choice;
        cout << endl;

        if (choice == 1)
        {
            createSavings(Account, aIndex); // go to function
            cout << endl;
        }
        else if (choice == 2)
        {
            createChecking(Account, aIndex);
            cout << endl;
        }
        else if (choice == 3)
        {
            createBank(Account, aIndex);
            cout << endl;
        }
        else if (choice == 4)
        {
            depositBank(Account, aIndex);
            cout << endl;
        }
        else if (choice == 5)
        {
            withdrawBank(Account, aIndex);
            cout << endl;
        }
        else if (choice == 6)
        {
            displayBank(Account, aIndex);
        }
        else if (choice == 7)
        {
            scBank(Account, aIndex);
            cout << endl;
        }
        else if (choice == 8)
        {
            exit(0); // end program
        }
        else
        {
            cout << "Invalid choice! Please try again!" << endl;
        }
    }

    return 0; // send 0 to operating system
}

// function that creates a savings account for a bank
void createSavings(Bank *Account[], int &aIndex)
{
    // local variable
    double iRate;
    int cPeriod;
    int aNumber;
    string aName;
    double aBalance;
    bool found = false;
    string aType = "Savings";

    if (aIndex > 100)
    {
        cout << "There cannot be more than 100 accounts." << endl;
        return; // go back to original function
    }

    cout << "Account number: ";
    cin >> aNumber;
    cout << endl;

    for (int i = 0; i < aIndex; i++)
    {
        if (aNumber == Account[i]->getAccountNumber()) // if account number exists
        {
            cout << "That account number already exists." << endl;
            found = true;
            break; // end for loop
        }
    }
    if (found == true)
    {
        return; // go back to original function
    }

    cout << "Account holder's name: ";
    cin >> aName;
    cout << endl;

    cout << "Account balance: ";
    cin >> aBalance;
    cout << endl;

    cout << "Interest rate: ";
    cin >> iRate;
    cout << endl;

    cout << "Compounding period: ";
    cin >> cPeriod;
    cout << endl;

    Savings *acc = new Savings(iRate, cPeriod, aNumber, aName, aBalance, aType); // save values to savings account object

    Account[aIndex] = acc;  // have bank index be that savings account
    aIndex++; // increment counter

    cout << "Task completed." << endl;
}

// function that creates a checking account for a bank
void createChecking(Bank *Account[], int &aIndex)
{
    // local variables
    double mBalance;
    int mFee;
    int aNumber;
    string aName;
    double aBalance;
    bool found = false;
    string aType = "Checking";

    if (aIndex > 100)
    {
        cout << "There cannot be more than 100 accounts." << endl;
        return; // back to original function
    }

    cout << "Account number: ";
    cin >> aNumber;
    cout << endl;

    for (int i = 0; i < aIndex; i++)
    {
        if (aNumber == Account[i]->getAccountNumber()) // if account number already exists
        {
            cout << "That account number already exists." << endl;
            found = true;
            break; // end for loop
        }
    }
    if (found == true)
    {
        return; // back to original function
    }

    cout << "Account holder's name: ";
    cin >> aName;
    cout << endl;

    cout << "Minimum balance: ";
    cin >> mBalance;
    cout << endl;

    aBalance = mBalance;

    cout << "Monthly fee: ";
    cin >> mFee;
    cout << endl;

    Checking *acc = new Checking(mBalance, mFee, aNumber, aName, aBalance, aType); // save value to checking account object

    Account[aIndex] = acc; // have bank index be that checking account
    aIndex++; // increment counter

    cout << "Task completed." << endl;
}

// function that creates a bank object with no parameters
void createBank(Bank *Account[], int &aIndex)
{
    int choice;

    while(true)
    {
        cout << "1. Savings account." << endl;
        cout << "2. Checking account." << endl;

        cout << "My choice: ";
        cin >> choice;
        cout << endl;

        if (choice == 1)
        {
            Savings *acc = new Savings(); // new bank object with savings
            Account[aIndex] = acc;
            aIndex++;
            break; // end while loop
        }
        else if (choice == 2)
        {
            Checking *acc = new Checking(); // new bank object with checking
            Account[aIndex] = acc;
            aIndex++;
            break;
        }
        else
        {
            cout << "Incorrect option. Please enter 1 or 2." << endl;
        }

    }

    cout << "Task completed." << endl;
}


// function that deposits money to user's bank account
void depositBank(Bank *Account[], int &aIndex)
{
    // local variables
    int aNumber;
    double depos;
    double nBalance;
    bool found = false;

    cout << "Account number: ";
    cin >> aNumber;
    cout << endl;

    for (int i = 0; i < aIndex; i++) // loop iteration
    {
        if (aNumber == Account[i]->getAccountNumber()) // account number matches
        {
            cout << "Deposit amount: ";
            cin >> depos;
            cout << endl;

            nBalance = Account[i]->deposit(depos); // go to function with depos money and store in nBalance variable

            found = true;

            cout << "New balance: $" << setprecision(2) << fixed << nBalance << endl;
        }
    }

    if (found == false)
    {
        cout << "That account number doesn't exist." << endl;
    }
}

// function that withdraws money from user's bank account
void withdrawBank(Bank *Account[], int &aIndex)
{
    // local variables
    int aNumber;
    double wBank;
    string rBalance;
    bool found = false;

    cout << "Account number: ";
    cin >> aNumber;
    cout << endl;

    for (int i = 0; i < aIndex; i++) // loop iteration
    {
        if (aNumber == Account[i]->getAccountNumber()) // if account number matches
        {
            cout << "Withdraw amount: ";
            cin >> wBank;
            cout << endl;

            rBalance = Account[i]->withdraw(wBank); // go to withdraw function using withdraw amount and save to rBalance

            found = true;

            if (rBalance != "Insufficient balance")
            {
                cout << "Remaining balance: $" << setprecision(2) << fixed << rBalance << endl;
            }
            else
            {
                cout << "Insufficient balance." << endl;
            }
        }
    }

    if (found == false)
    {
        cout << "That account number doesn't exist." << endl;
    }
}

// function that displays all of the bank accounts
void displayBank(Bank *Account[], int &aIndex)
{
    for (int i = 0; i < aIndex; i++) // loop iteration
    {
        displayAccountInfo(*Account[i]); // go to function in Bank.cpp file with account info
        cout << endl;
    }
}

// function that applies interest to savings, or charge fee for checking
void scBank(Bank *Account[], int &aIndex)
{
    // local variable
    int aNumber;
    int choice;
    bool found = false;
    int index;
    cout << "Account number: ";
    cin >> aNumber;
    cout << endl;

    for (int i = 0; i < aIndex; i++) // loop iteration
    {
        if (aNumber == Account[i]->getAccountNumber()) // account number matches
        {
            Account[i]->getType(); // get account type
            found = true;
            index = i;
        }
    }
    if (found == false)
    {
        cout << "That account number does not exist for a savings account." << endl;
    }
    else // account type check
    {
        if (Account[index]->getType() == "Savings")
        {
            Account[index]->addInterest(); // go to saving member function
            cout << "Task completed." << endl;
        }
        else if (Account[index]->getType() == "Checking")
        {
            Account[index]->chargeFee(); // go to checking member function
            cout << "Task completed." << endl;
        }
    }
}

