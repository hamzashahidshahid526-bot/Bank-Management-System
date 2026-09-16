#include <iostream>
#include "SavingsAccount.h"
using namespace std;
SavingsAccount::SavingsAccount(string n, double b, int p, int a, double i) : accounts(n, b, p, a)
{
    interest_rate = i;
}
void SavingsAccount::add_interest()
{
    double interest = balance * interest_rate / 100.0;
    balance += interest;
    cout << "Interest addeed Sucessfully. New Balance: " << balance << endl;
}