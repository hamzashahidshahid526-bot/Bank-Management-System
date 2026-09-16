#ifndef CheckingAccount_h
#define CheckingAccount_h
#include "Account.h"
class CheckingAccount : public accounts
{
private:
    double overdraft_limit;

public:
    CheckingAccount(std::string n, double b, int p, int a, double ol);
    bool withdraw(double amount) override;
};
#endif