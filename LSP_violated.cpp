#include<iostream>
#include<vector>
using namespace std;

class Account{
public:
    virtual void deposite(double amount) = 0;
    virtual void withdraw(double amount) = 0;
};

class SavinAccount : public Account{
private:
    double balance;
public:
    SavinAccount(){
        balance = 0;
    }

    void deposite(double amount){
        balance += amount;
        cout<<"Deposited: "<<amount<<" in Savings Account. New Balance: "<<balance<<endl;
    }

    void withdraw(double amount){
        if(balance >= amount){
            balance -= amount;
            cout<<"Withdraw: "<<amount<<" from Savings Account. New Balance: "<<balance<<endl;
        }
        else{
            cout<<"Insufficient funds in Saving Account!\n";
        }
    }
};

class CurrentAccount : public Account{
private:
    double balance;
public:
    CurrentAccount(){
        balance = 0;
    }

    void deposite(double amount){
        balance += amount;
        cout<<"Deposited: "<<amount<<" in Current Account. New Balance: "<<balance<<endl;
    }

    void withdraw(double amount){
        if(balance >= amount){
            balance -= amount;
            cout<<"Withdraw: "<<amount<<" from Current Account. New Balance: "<<balance<<endl;
        }
        else{
            cout<<"Insufficient funds in Current Account!\n";
        }
    } 
};

class FixedAccount : public Account{
private:
    double balance;
public:
    FixedAccount(){
        balance = 0;
    }

    void deposite(double amount){
        balance += amount;
        cout<<"Deposited: "<<amount<<" in Fixed Account. New Balance: "<<balance<<endl;
    }

    void withdraw(double amount){
        throw logic_error("Withdrawal Not Allowed in fixed term Account!");
    }
};

class BankClient {
private:
    vector<Account*> accounts;
public:
    BankClient(vector<Account*> accounts){
        this->accounts = accounts;
    }

    void processTransactions(){
        for(Account* acc : accounts){
            acc->deposite(1000);

        //  Asuming all acount support: support withdrawal (LSP violated)
        try {
            acc->withdraw(500);
        } 
        catch (const logic_error& e) {
            cout << "Exception : " << e.what() << endl;
        }
        }
    }
};

int main(){
    vector<Account*> accounts;
    accounts.push_back(new SavinAccount());
    accounts.push_back(new CurrentAccount());
    accounts.push_back(new FixedAccount());

    BankClient* client = new BankClient(accounts);
    client->processTransactions();  // Trows exception when withdrawing from FixedAccount
    return 0;

}

// ===========================================================================================
//                                       OUTPUT
// ===========================================================================================


                                // Deposited: 1000 in Savings Account. New Balance: 1000
                                // Withdraw: 500 from Savings Account. New Balance: 500
                                // Deposited: 1000 in Current Account. New Balance: 1000
                                // Withdraw: 500 from Current Account. New Balance: 500
                                // Deposited: 1000 in Fixed Account. New Balance: 1000
                                // Exception : Withdrawal Not Allowed in fixed term Account!
  

// ============================================================================================

