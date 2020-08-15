#ifndef BANK_H_INCLUDED
#define BANK_H_INCLUDED
#include <string>

using namespace std;

class Bank
{
    protected:
        int accountNumber;
        string name;
        double balance;
        string accountType;
    public:
        //constrctors
        Bank();
        Bank(int, string, double, string);
        //mutators
        string withdraw(double);
        double deposit(double);
        void setName(string n)
        {
            name = n;
        }
        // accessors
        int getAccountNumber()
        {
            return accountNumber;
        }
        string getName()
        {
            return name;
        }
        double getBalance()
        {
            return balance;
        }
        string getType()
        {
            return accountType;
        }

        virtual double addInterest()
        {
            return 0;
        }
        virtual double chargeFee()
        {
            return 0;
        }

};

class Savings : public Bank
{
    protected:
        double interestRate;
        int compoundPeriod;
    public:
        // constructors
        Savings();
        Savings(double, int, int, string, double, string);
        // mutators
        double addInterest();
        void setInterestRate(double iR)
        {
            interestRate = iR;
        }
        void setPeriod(int p)
        {
            compoundPeriod = p;
        }
        // accessors
        double getInterestRate() const
        {
            return interestRate;
        }
        int getPeriod() const
        {
            return compoundPeriod;
        }
};

class Checking : public Bank
{
    private:
        double minBalance;
        double monFee;
    public:
        // constructors
        Checking();
        Checking(double, double, int, string, double, string);
        // mutators
        double chargeFee();
        void setBalance(double b)
        {
            minBalance = b;
        }
        void setFee(double f)
        {
            monFee = f;
        }
        // accessors
        double getBalance() const
        {
            return minBalance;
        }
        double getFee() const
        {
            return monFee;
        }
};
#endif // BANK_H_INCLUDED
