#include "Account.h"
#include <iostream>
#include <fstream>
#include "Transaction.h"
#include <time.h>
#include <cstring>
using namespace std;
void saveTofile(std::string name, int acc_no, std::string type, double amount, double balance, int p)
{
    // check if csv need header
    ifstream check("transactions.csv");
    bool needHeader = check.peek() == ifstream ::traits_type::eof();
    check.close();
    std::ofstream file("transactions.txt", std::ios::app);
    ofstream csv("transactions.csv", ios::app);
    if (file.is_open())
    {
        time_t now = time(0);
        char *dt = ctime(&now);
        dt[strlen(dt) - 1] = '\0'; // Remove the newline character from the end of the string
        if (needHeader)
        {
            csv << "Account Holder Name,Account Number,PIN,Transaction Type,Amount,Balance,Date\n";
        }
        file << "Account Holder Name: " << name << std::endl;
        file << "Account Number: " << acc_no << std::endl;
        file << "Transaction Type: " << type << std::endl;
        file << "Amount: " << amount << std::endl;
        file << "Balance: " << balance << std::endl;
        file << "PIN : " << p << endl;
        file << "Date: " << dt << std::endl;
        file << "------------------------" << std::endl;
        csv << name << "," << acc_no << "," << p << "," << type << "," << amount << "," << balance << "," << dt << "\n";
        file.close();
        csv.close();
    }
    else
    {
        std::cout << "Unable to open file for writing." << std::endl;
    }
}
void accounts::deposit(double amount)
{
    balance += amount;
    cout << "deposit Successfull !" << endl;
    transactions[index].type = "Deposit";
    transactions[index].amount = amount;
    index++;
    saveTofile(name, acc_no, "Deposit", amount, balance, pin);
}
bool accounts::withdraw(double amount)
{
    if (balance >= amount)
    {
        balance -= amount;
        cout << "Withdrawal successful!" << endl;
        transactions[index].type = "Withdrawal";
        transactions[index].amount = amount;
        index++;
        saveTofile(name, acc_no, "Withdrawal", amount, balance, pin);
        return true;
    }
    else
    {
        std::cout << "Insufficient balance!" << std::endl;
        return false;
    }
}
void accounts::display()
{
    std::cout << "Account Number: " << acc_no << std::endl;
    std::cout << "Name: " << name << std::endl;
    std::cout << "Balance: " << balance << std::endl;
}
accounts::accounts(std::string n, double b, int p, int a)
{
    name = n;
    balance = b;
    pin = p;
    acc_no = a;
}
int accounts::getAccno()
{
    return acc_no;
}
