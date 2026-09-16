#ifndef Transaction_H
#define Transaction_H
#include <string>
class Transaction
{
public:
    Transaction(std::string t, double a, std::string d);
    Transaction();
    void display();
    std::string type;
    double amount;
    std::string date;
    int index;
    int transactions[100];
};
#endif