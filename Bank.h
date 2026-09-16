#ifndef Bank_H
#define Bank_H
#include "Account.h"
class Bank
{
private:
    accounts *allaccounts[100];
    int totalaccounts;

public:
    Bank();
    void addAccount(accounts *acc);
    accounts *findaccounts(int acc_no);
    void showAllaccounts();
    ~Bank();
};
#endif