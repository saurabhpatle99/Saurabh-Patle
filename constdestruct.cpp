#include <iostream>

using namespace std;

class calculator
{
    float a,b,c,d,e,f,x,y;
    int g,h;

public :
    calculator()
    {
        x=0;
        y=0;
        a=0;b=0;c=0;d=0;e=0;f=0;x=0;y=0;
        g=0;h=0;
    }

    void add(float x,float y)
    {
        cout<<"Sum of "<<x<<" and "<<y<<" is : "<<(x+y);
    }
    void sub(float a,float b)
    {
        cout<<"Difference of "<<a<<" and "<<b<<" is : "<<(a-b);
    }
    void mul(float c,float d)
    {
        cout<<"Multiplication of "<<c<<" and "<<d<<" is : "<<(c*d);
    }
    void div(float e,float f)
    {
        cout<<"Quotient of "<<e<<" and "<<f<<" is : "<<(e/f);
    }
    void mod(int g,int h)
    {
        cout<<"Remainder of "<<g<<" and "<<h<<" is : "<<(g%h);
    }
    ~calculator()
    {
    cout<<"\nDestructor called\n";
    }
};
int main()
{
    int i;
    float a,b,c,d,e,f,x,y;
    int g,h;
    calculator obj;
    again :
    cout<<"Choose the mathematical operation you want to perform";
    cout<<"\nFor Addition press 1  \nFor Subtraction press 2  \nFor Multiplication press 3   \nFor Division press 4  \nFor getting remainder press 5  \n\n";
    cin>>i;
    if (i==1)
    {
       cout<<"Enter two numbers ";
       cin>>x>>y;
       obj.add(x,y);
    }
    else  if (i==2)
    {
       cout<<"Enter two numbers ";
       cin>>a>>b;
       obj.sub(a,b);
    }
    else if (i==3)
    {
       cout<<"Enter two numbers ";
       cin>>c>>d;
       obj.mul(c,d);
    }
    else if (i==4)
    {
       cout<<"Enter two numbers ";
       cin>>e>>f;
       obj.div(e,f);
    }
    else if (i==5)
    {
       cout<<"Enter two numbers ";
       cin>>g>>h;
       obj.mod(g,h);
    }
    else
    {
       cout<<"\nYou chose an invalid option";

    }
    int z;
    cout<<"\nif you want to perform another operation press 1  \nTo terminate press 2  \n";
    cin>>z;
    if (z==1)
    {
        goto again;
    }

    return 0;
}


