#include "SavingsAccount.h"
#include "CheckingAccount.h"
#include "Bank.h"
#include <iostream>
#include <limits>
#include <string>
#include <fstream>
using namespace std;
int getIntinput(std::string msg)
{
    int input;
    while (true)
    {
        std::cout << msg;
        std::cin >> input;

        if (std::cin.fail())
        {
            std::cout << "Invalid input. Please enter an integer." << std::endl;
            std::cin.clear();                                                   // Clear the error flag
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Discard invalid input
        }
        else
        {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Discard any remaining input
            return input;
        }
    }
}
using namespace std;
int main()
{
    Bank mybank;
    int choice;
    cout << "========== Welcome to the Bank Management System ==========" << endl;
    do
    {
        cout << "\n-----Menu-----" << endl;
        cout << "1. Create A Normal Account" << endl;
        cout << "2. Create A Savings Account" << endl;
        cout << "3. Create A Checking Account" << endl;
        cout << "4. Display All Accounts" << endl;
        cout << "5. Find An Account" << endl;
        cout << "6. Deposit Money" << endl;
        cout << "7. Withdraw Money" << endl;
        cout << "8. Show Transactions History" << endl;
        cout << "9. Exit" << endl;
        int choice = getIntinput("Enter your choice: ");
        if (choice == 1)
        {
            string name;
            cout << "Enter Account Holder Name: ";
            cin >> name;
            double balance = getIntinput("Enter Initial Balance: ");
            int PIN = getIntinput("Enter PIN: ");
            int acc_no = getIntinput("Enter Account Number: ");
            mybank.addAccount(new accounts(name, balance, PIN, acc_no));
            cout << "Account Created Successfully!" << endl;
        }
        else if (choice == 2)
        {
            string name;
            cout << "Enter Account Holder Name: ";
            cin >> name;
            double balance = getIntinput("Enter Initial Balance: ");
            int PIN = getIntinput("Enter PIN: ");
            int acc_no = getIntinput("Enter Account Number: ");
            double interest_rate = getIntinput("Enter Interest Rate: ");
            mybank.addAccount(new SavingsAccount(name, balance, PIN, acc_no, interest_rate));
            cout << "Savings Account Created Successfully!" << endl;
        }
        else if (choice == 3)
        {
            string name;
            double balance = getIntinput("Enter Initial Balance: ");
            int PIN = getIntinput("Enter PIN: ");
            int acc_no = getIntinput("Enter Account Number: ");
            double overdraft_limit = getIntinput("Enter Overdraft Limit: ");
            cout << "Enter Account Holder Name: ";
            cin >> name;
            mybank.addAccount(new CheckingAccount(name, balance, PIN, acc_no, overdraft_limit));
            cout << "Checking Account Created Successfully!" << endl;
        }
        else if (choice == 4)
        {
            mybank.showAllaccounts();
        }
        else if (choice == 5)
        {
            int acc_no = getIntinput("Enter Account Number to Find: ");
            accounts *acc = mybank.findaccounts(acc_no);
            if (acc != nullptr)
            {
                acc->display();
            }
            else
            {
                cout << "Account not found!" << endl;
            }
        }
        else if (choice == 6)
        {
            int acc_no = getIntinput("Enter Account Number to Deposit Money: ");
            int entered_pin = getIntinput("Enter the PIN of this account : ");
            accounts *acc = mybank.findaccounts(acc_no);
            if (acc != nullptr)
            {
                if (acc->get_pin() != entered_pin)
                {
                    cout << "Wrong PIN and cannot deposit money ";
                }
                else
                {
                    double amount = getIntinput("Enter amount to deposit : ");
                    acc->deposit(amount);
                }
            }
            else
            {
                cout << "Account not found!" << endl;
            }
        }
        else if (choice == 7)
        {
            int acc_no = getIntinput("Enter Account Number to Withdraw Money: ");
            int entered_pin = getIntinput("Enter the PIN of this account : ");
            accounts *acc = mybank.findaccounts(acc_no);
            if (acc != nullptr)
            {
                if (acc->get_pin() != entered_pin)
                {
                    cout << "Wrong PIN cannot withdraw money ";
                }
                else
                {
                    double amount = getIntinput("Enter Amount to Withdraw: ");
                    acc->withdraw(amount);
                }
            }
            else
            {
                cout << "Account not found!" << endl;
            }
        }
        else if (choice == 8)
        {
            ifstream file("transactions.txt");
            if (!file.is_open())
            {
                cout << "No transactions found." << endl;
            }
            else
            {
                string line;
                while (getline(file, line))
                {
                    cout << line << endl;
                }
                file.close();
            }
        }
        else if (choice == 9)
        {
            cout << "Thanks for using our banking system. Exiting..." << endl;
        }
        else
        {
            cout << "Invalid choice!" << endl;
        }

    } while (choice != 8);
    return 0;
}