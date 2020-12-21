#include <iostream>

using namespace std;

double area(double r)
{

    cout<< "area of circle is : " <<(3.141592653589793238)*(r*r);

}

double area(double b,double h)
{

    cout<< "area of triangle is : " <<0.5*b*h;

}

int area(int p,int q)
{

    cout<< "area of rectangle is : " <<p*q;

}

int main()
{
    double b,h,r,i;
    int p,q;
    cout<<"\nEnter the shape ,    for circle press 1   For triangle press 2  for rectangle press 3\n";
    cin>>i;
    if(i==1)
    {
    cout<< "\nEnter radius ";
    cin>> r;
    area(r);
    }
    else if(i==2)
    {
    cout<< "\nEnter Base and height ";
    cin>> b>>h;
    area(b,h);
    }
    else if(i==3)
    {
       cout<< "\nEnter length and breadth ";
       cin>> p>>q;
       area(p,q);
    }

    else
    {
        cout<< "Entered shape is invalid";
    }



    return 0;
}
