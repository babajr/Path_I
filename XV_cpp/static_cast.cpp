#include <iostream>
using namespace std;

// Static Cast: Built-in Types
// int main()
// {
//     int i = 2;
//     double d = 3.7;
//     double *pd = &d;

//     i = d;                   // implicit -- warning
//     i = static_cast<int>(d); // static_cast -- okay
//     i = (int)d;              // C-style -- okay

//     d = i;                      // implicit -- okay
//     d = static_cast<double>(i); // static_cast -- okay
//     d = (double)i;              // C-style -- okay

//     i = pd;                   // implicit -- error
//     i = static_cast<int>(pd); // static_cast -- error
//     i = (int)pd;              // C-style -- okay: RISKY: Should use reinterpret_cast
//                               // okay only when sizeof(int) = sizeof(double *)
//     return 0;
// }

// Static Cast: Class Hierarchy
class A
{
};

class B : public A
{
};

int main()
{
    A a;
    B b;

    // UPCAST
    A *p = &b;                // implicit -- okay
    p = static_cast<A *>(&b); // static_cast -- okay
    p = (A *)&b;              // C-style -- okay

    // DOWNCAST
    B *q = 0;
    q = &a;                   // implicit -- error
    q = static_cast<B *>(&a); // static_cast -- okay: RISKY: Should use dynamic_cast
    q = (B *)&a;              // C-style -- okay

    return 0;
}