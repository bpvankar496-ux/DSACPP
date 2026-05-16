//Q2: BankAccount Class
#include <iostream>
using namespace std;

class BankAccount {
private:
    int accountNumber;
    double balance;

public:
    BankAccount(int accNum, double bal) {
        accountNumber = accNum;
        balance = bal;
    }

    void deposit(double amount) {
        balance += amount;
    }

    void withdraw(double amount) {
        if (balance >= amount)
            balance -= amount;
        else
            cout << "Insufficient balance, cur balance: " << balance << endl;
    }

    double getBalance() {
        return balance;
    }
};

int main() {
    BankAccount myAccount(12345, 40.5);
    myAccount.deposit(100.5);
    myAccount.withdraw(30.5);
    cout << "Current balance: " << myAccount.getBalance() << endl;
    return 0;
}
//ANS:=
//Current balance: 110.5