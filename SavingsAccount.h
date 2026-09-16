#ifndef SavingsAccount_h
#define SavingsAccount_h
#include "Account.h"
class SavingsAccount : public accounts
{
private:
    double interest_rate;

public:
    SavingsAccount(std::string n, double b, int p, int a, double i);
    void add_interest();
};
#endif