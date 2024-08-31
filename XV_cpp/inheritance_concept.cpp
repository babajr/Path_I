#include <iostream>
using namespace std;

// Base Class
class B
{
protected:
    int data_;

public:
    B(int d = 0) : data_(d) // Constructor
    {
        cout << "B::B(int): " << data_ << endl;
    }

    ~B() // Destructor
    {
        cout << "B::~B(): " << data_ << endl;
    }
};

// Derived class
class D : public B
{
    int info_;

public:
    D(int d, int i) : B(d), info_(i) // Explicit construction of Base :
                                     // Constructor Class B and Class D
    {
        cout << "D::D(int, int): " << data_ << ", " << info_ << endl;
    }

    D(int i) : info_(i) // Default construction of Base: Constructor (Class D)
    {
        cout << "D::D(int): " << data_ << ", " << info_ << endl;
    }

    ~D()
    {
        cout << "D::~D(): " << data_ << ", " << info_ << endl;
    }
};

int main()
{
    B b(0);     // Base Class Object
    D d1(1, 2); // Derived Class Object
    D d2(3);    // Derived Class Object

    return 0;
}