/*
A friend function of a class
-- has access to the private and protected members of the class
   (breaks the encapsulation)
-- must have its prototype included within the scope of the class prefixed
   with the keyword friend
-- does not have its name qualified with the class scope
-- is not called with an invoking object of the class
-- can be declared friend in more then one classes

A friend function can be a
-- global function
-- a member function of a class
-- a function template
*/

#include <iostream>
using namespace std;

class FriendClass
{
private:
    int data_;

public:
    FriendClass(int i) : data_(i)
    {
        cout << "Ctor" << endl;
    }

    ~FriendClass()
    {
        cout << "Dtor" << endl;
    }

    friend void display(const FriendClass &a);
};

void display(const FriendClass &a)
{
    cout << a.data_ << endl;
}

int main(void)
{
    FriendClass obj1(10);
    display(obj1);

    return 0;
}
