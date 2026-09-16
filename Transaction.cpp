#include "Transaction.h"
#include <iostream>
using namespace std;
Transaction::Transaction()
{
    amount = 0.0;
    type = "";
    date = "";
}
Transaction::Transaction(std::string t, double a, std::string d)
{
    type = t;
    amount = a;
    date = d;
}
void Transaction::display()
{
    cout << "Transaction Type: " << type << endl;
    cout << "Amount: " << amount << endl;
    cout << "Date: " << date << endl;
}