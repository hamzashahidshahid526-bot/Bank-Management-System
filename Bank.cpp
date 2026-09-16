#include "Bank.h"
#include <iostream>
using namespace std;
Bank::Bank()
{
    totalaccounts = 0;
}
void Bank::addAccount(accounts *acc)
{
    if (totalaccounts < 100)
    {
        allaccounts[totalaccounts] = acc;
        totalaccounts++;
        cout << "Account # " << acc->getAccno() << " has been added successfully." << endl;
    }
    else
    {
        cout << "Cannot add more accounts. Maximum limit reached." << endl;
    }
}
accounts *Bank::findaccounts(int acc_no)
{
    for (int i = 0; i < totalaccounts; i++)
    {

        if (allaccounts[i]->getAccno() == acc_no)
        {
            return allaccounts[i];
        }
    }
    cout << "Account # " << acc_no << " not found" << endl;
    return nullptr;
}
void Bank::showAllaccounts()
{
    if (totalaccounts == 0)
    {
        cout << "No accounts to display." << endl;
        return;
    }
    cout << "\n----- All Accounts in Bank (Total: " << totalaccounts << ") -----" << endl;
    for (int i = 0; i < totalaccounts; i++)
    {
        allaccounts[i]->display();
        cout << "----------------------------------------" << endl;
    }
}
Bank::~Bank()
{
    for (int i = 0; i < totalaccounts; i++)
    {
        delete allaccounts[i];
    }
    cout << "Memeory Freed , All accounts has been deleted and Bank is closed" << endl;
}