#include<iostream>

using namespace std;

// Class Inverients of a parent class should not be broken by child class object.
// Hence child class can either maintain or strengthen the invarient but never narrows it down.

// Invarient: balance cannot be negative
class BankAccount{
protected:
    double balance;
public:
    BankAccount(double b){
        if(b < 0) throw invalid_argument("balance can't be Negative");
        balance = b;
    }

    virtual void withdraw(double amount){
        if(balance - amount < 0) throw runtime_error("Insufficient Balnce");
        balance -= amount;
        cout<<"Amount withdraw remaining balance: "<<balance<<endl;
    }
};

class CheatAccount : public BankAccount{
public:
    CheatAccount(double b) : BankAccount(b){}

    void withdraw(double amount) override {
        balance -= amount; // LSP break! Negative balance alowed
        cout<<"Amount withdrwn. Remaining balnce: "<<balance<<endl;
    }
};

int main(){
    BankAccount* bankAccount = new BankAccount(100);
    bankAccount->withdraw(10);
}