#include <iostream>
using namespace std;

class A
{
    int i_;

public:
    A(int i) : i_(i) {} // Constructor

    int get() const { return i_; } // Const member function

    void set(int j) { i_ = j; } // Member function
};

// Global Function
void print(char *str) { cout << str << endl; }

int main()
{
    const char *c = "sample text"; // Pointer to a constant string

    // print(c); // error: ’void print(char *)’: cannot convert argument 1 // from ’const char *’ to ’char *’

    print(const_cast<char *>(c));

    const A a(1); // Constant Object

    a.get();
    // a.set(5); // error: ’void A::set(int)’: cannot convert // ’this’ pointer from ’const A’ to ’A &’

    const_cast<A &>(a).set(5); // Creating Reference to Object a.
    // const_cast<A>(a).set(5); // error: ’const_cast’: cannot convert from ’const A’ to ’A’
    // Change to the object a is not allowed.

    return 0;
}