#include <iostream>
#include <string>
using namespace std;

class BankAccount
{
    private:
    int balance;
    
    public:
    BankAccount()
    {
        balance = 100;
    }
    BankAccount(int bal)
    {
        balance = bal;
        
    }
    
    BankAccount(BankAccount &BA)
    {
        balance = BA.balance - 200;
    }
    
    void print()
    {
        cout<<"Balance : " << balance<< endl;
    }
    
};


int main() 
{
    cout<<"Account 1 ";
    BankAccount account1;
    account1.print();
    cout<<"Account 2 ";
    BankAccount account2(1000);
    account2.print();
    cout<<"Account 3 ";
    BankAccount account3(account2);
    account3.print();
    cout<<"Account 2 ";
    account2.print();
    
    return 0;
}
