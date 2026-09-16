#ifndef Account_H
#define Account_H
#include "Transaction.h"
#include <string>
class accounts
{
protected:
    std::string name;
    double balance;
    int pin;
    int acc_no;

public:
    void display();
    virtual void deposit(double amount);
    virtual bool withdraw(double amount);
    accounts(std::string n, double b, int p, int a);
    int getAccno();
    int index;
    Transaction transactions[100];
    int get_pin()
    {
        return pin;
    }
};
#endif