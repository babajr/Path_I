#include <iostream>
#include <cmath>
using namespace std;

/*
Copy Constructors:
-- A new object is created.
-- The new object is initialized with the value of
   data members of another object.

Copy Assignment Operator:
-- An object is already existing (and initialized).
-- The members of the existing object are replaced by
   values of data members of another object.

Deep and Shallow Copy for Pointer Members:
-- Deep copy allocates new space for the contents and copies
   the pointed data.
-- Shallow copy merely copies the pointer value – hence,
   the new copy and the original pointer continue to point to
   the same data.
*/

class Complex
{
    double re_, im_;

public:
    Complex() : re_(0.0), im_(0.0) // Default Constructor
    {
        cout << "Default ctor: ";
        print();
    }

    Complex(double re, double im) : re_(re), im_(im) // Parameterised Constructor
    {
        cout << "Parameterised ctor: ";
        print();
    }

    Complex(const Complex &c) : re_(c.re_), im_(c.im_) // Copy Constructor
    {
        cout << "Copy ctor: ";
        print();
    }

    ~Complex() // Destructor
    {
        cout << "dtor: ";
        print();
    }

    Complex &operator=(const Complex &c) // Copy Assignment Operator
    {
        re_ = c.re_;
        im_ = c.im_;
        cout << "Copy Assignment Operator: ";
        print();
        return *this;
    }

    double norm()
    {
        return sqrt(re_ * re_ + im_ * im_);
    }

    void print()
    {
        cout << "|" << re_ << "+j" << im_ << "| = " << norm() << endl;
    }
};

int main()
{
    Complex c1(4.2, 5.3); // Constructor - Complex(double, double)
    Complex c2(7.9, 8.5); // Constructor - Complex(double, double)
    Complex c3(c2);       // Copy Constructor - Complex(const Complex& c)
    Complex c4;           // Default Constructor
    c1.print();
    c2.print();
    c3.print();
    c2 = c1; // Copy Assignment Operator
    c2.print();
    c1 = c2 = c3; // Copy Assignment Chain
    c1.print();
    c2.print();
    c3.print();

    return 0;
}