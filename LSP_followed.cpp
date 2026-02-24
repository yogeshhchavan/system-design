#include<iostream>
#include<vector>
#include<typeinfo>
#include<stdexcept>
using namespace std;

class DepositeAcoount {
public :
    virtual void deposite(double mount) = 0;
};

class withdrwalAccount : public DepositeAcoount {
public:
    virtual void withdraw(double amount) = 0;
};

class savingAccount : public withdrwalAccount {
private:
    double balance;
public:
    savingAccount() {
        balance = 0;
    }

    void deposite(double amount) {
        balance += amount;
        cout << "Deposited: " << amount << " in Saving Account. New Balance: " << balance << endl;
    }

    void withdraw(double amount) {
        if (balance >= amount) {
            balance -= amount;
            cout << "Withdraw: " << amount << " from Saving Account. New Balance: " << balance << endl;
        }
        else {
            cout << "Insufficient funds in Saving Account!\n";
        }
    }
};

class currentAccount : public withdrwalAccount {
private:
    double balance;
public:
    currentAccount() {
        balance = 0;
    }

    void deposite(double amount) {
        balance += amount;
        cout << "Deposited: " << amount << " in Current Account. New Balance: " << balance << endl;
    }

    void withdraw(double amount) {
        if (balance >= amount) {
            balance -= amount;
            cout << "Withdraw: " << amount << " from Current Account. New Balance: " << balance << endl;
        }
        else {
            cout << "Insufficient funds in Current Account!\n";
        }
    }
};

class fixedAccount : public DepositeAcoount {
private:
    double balance; 
public:
    fixedAccount() {
        balance = 0;
    }

    void deposite(double amount) {
        balance += amount;
        cout << "Deposited: " << amount << " in Fixed Account. New Balance: " << balance << endl;
    }
};

class BankClient{
private:
    vector<withdrwalAccount*> withdrwalAccounts;
    vector<DepositeAcoount*> depositeAcoounts;

public:
    BankClient(vector<withdrwalAccount*> withdrwalAccounts, 
        vector<DepositeAcoount*> depositeAcoounts){
        this->withdrwalAccounts = withdrwalAccounts;
        this->depositeAcoounts = depositeAcoounts; 
    }

    void processTransactions(double amount){
        for(withdrwalAccount* acc : withdrwalAccounts){
            acc->deposite(1000);
            acc->withdraw(500);
        }

        for (DepositeAcoount* acc : depositeAcoounts){
            acc->deposite(5000);
        }
    }
};

int main(){
    vector<withdrwalAccount*> withdrwalAccounts;
    withdrwalAccounts.push_back(new savingAccount());
    withdrwalAccounts.push_back(new currentAccount());

    vector<DepositeAcoount*> depositeAcoounts;
    depositeAcoounts.push_back(new fixedAccount());

    BankClient* client = new BankClient (withdrwalAccounts, depositeAcoounts);
    client->processTransactions(500);
    return 0;
}



// =====================================================================================
//                                       OUTPUT
// =====================================================================================

//                           Deposited : 1000 in Saving Account. New Balance: 1000
//                           Withdraw: 500 from Saving Account. New Balance: 500
//                           Deposited: 1000 in Current Account. New Balance: 1000
//                           Withdraw: 500 from Current Account. New Balance: 500
//                           Deposited: 1000 in Fixed Account. New Balance: 1000
//                           Skipping withdraw for fixed term Account.

// ===========================================================================================

  
