#include <iostream>
#include "memory"
using namespace std;

/*
A friend class of a class
-- has access to the private and protected members of the class (breaks the encapsulation)
-- does not have its name qualified with the class scope (not a nested class)
-- can be declared friend in more then one classes

A friend class can be a
-- class
-- class template
*/

class Test; // Forward Declaration

class Main
{
    int data;

public:
    Main()
    {
        cout << "Main : ctor" << endl;
    }

    friend class Test;         // friend class
    friend void temp(Main &a); // friend function
};

void temp(Main &a1)
{
    cout << "I am in friend temp function" << endl;
    a1.data = 3; // changing the private member value
}

class Test : public Main
{
public:
    Test()
    {
        cout << "Test : ctor" << endl;
    };

    void display()
    {
        cout << "I am in a friend class display function" << endl;
        data = 4;
    }
};
int main()
{
    Main a;
    Test p;
    p.display();
    temp(a);
}