/*
    An abstract class in C++ is a class that has at least one pure virtual function
    (i.e., a function that has no definition).
    The classes inheriting the abstract class must provide a definition for the pure virtual function.
*/
#include <iostream>
using namespace std;

class Base // Abstract Base Class
{
public:
    Base() {}
    virtual void display() = 0; // pure virtual function
};

class Derived : public Base // Concrete Class
{
public:
    Derived() {}
    void display()
    {
        cout << "I am in a display function";
    }
};

int main()
{
    // Creating a pointer of type Base pointing to an objectof type Derived
    Base *b1 = new Derived;
    b1->display();

    return 0;
}
