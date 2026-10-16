#include <iostream>
#include <string> 
using namespace std;

int main(){

class BankAccount{
private:
//Data members name and balance 
    string customer_name;
    float balance;



public:

    string getname() const{ return customer_name;}
    void setname(string n){ customer_name = n;}

    float getbalance() const{return balance;}
    void setbalance(float b){balance=b;}

    string deposit(float amount){
        balance = balance+amount;
        string update = "Now your balance is:"+ to_string(balance);
        return update;}


    string withdraw(float amount){
        balance = balance-amount;
        string update ="Now your balance is:"+ to_string(balance);
        return update;}
         
    };


}




