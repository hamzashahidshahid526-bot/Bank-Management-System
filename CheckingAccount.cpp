#include <iostream>
#include "CheckingAccount.h"
using namespace std;
CheckingAccount::CheckingAccount(std::string n, double b, int p, int a, double ol) : accounts(n, b, p, a)
{
    overdraft_limit = ol;
}
bool CheckingAccount::withdraw(double amount)
{
    if (balance + overdraft_limit >= amount)
    {
        balance -= amount;
        cout << "Withdrawal successful!" << endl;
        return true;
    }
    else
    {
        cout << "Insufficient funds!" << endl;
        return false;
    }
}