//Pin no. is 1234

#include <iostream>

using namespace std;

class atm
{

    double w,d,balance=1000.00;
public:
    void withdraw(double balance,double w)
    {
        cout<<"Please enter amount to withdraw: "<<endl;
        cin>>w;
        if(w<balance)
        {
          balance=balance-w;
          cout<<"Please collect your cash"<<endl;
          cout<<"Your available balance is: "<<balance<<endl;
        }
        else
        {
            cout<<"Insufficient balance to withdraw"<<endl;
        }

    }
    void deposit(double balance,double d)
    {
        cout<<"Please enter amount to deposit: "<<endl;
        cin>>d;
        if(d!=0)
        {
          balance=balance+d;
          cout<<"Thank you for depositing, your new balance is: "<<balance<<endl;
        }
        else
        {
            cout<<"Please enter valid amount to deposit"<<endl;
        }

    }

};
int main()
{
    int p,n,pin;
    double w,d,balance=1000.00;
    atm obj;
    again :
    cout << "***************WELCOME TO YOUR BANK***************" << endl;
    cout<<"\n\nEnter your pin number please :";
    cin>>pin;
    if(pin==1234)
    {
        cout<<"Enter any option to be served !"<< endl;
        cout<<"\n1. Balance Enquiry \n2. Cash Withdraw \n3. Deposit Cash \n4. Exit \nEnter your choice: "<< endl;
        cin>>n;
        if(n==1)
        {
          cout<<"Your bank balance is: "<<balance<<endl;
        }
        else if(n==2)
        {
          obj.withdraw(balance,w);
        }
        else if(n==3)
        {
            obj.deposit(balance,d);
        }
        else if(n==4)
        {
            cout<<"Thank you for banking with us, have a nice day!"<<endl;
            exit(0);
        }
        else
        {
        cout<<"Invalid Selection"<<endl;
        }
        cout<<"Do you want another transaction? \nPress 1 to proceed or 2 to exit"<<endl;
        cin>>p;
        if(p==1)
        {
            system("cls");
            goto again;
        }
        else
        {
            exit(0);
        }
    }
    else
    {
        cout<<"You entered wrong pin"<<endl;
    }
    return 0;
}
