#include <iostream>
#include <typeinfo>
using namespace std;

// Polymorphic Hierarchy
class A
{
public:
    virtual ~A() {}
};

class B : public A
{
};

int main()
{
    A a;
    cout << typeid(a).name() << ": "
         << typeid(&a).name() << endl; // Static

    A *p = &a;
    cout << typeid(p).name() << ": "
         << typeid(*p).name() << endl; // Dynamic

    B b;
    cout << typeid(b).name() << ": "
         << typeid(&b).name() << endl; // Static

    p = &b;
    cout << typeid(p).name() << ": "
         << typeid(*p).name() << endl; // Dynamic

    A &r1 = a;
    A &r2 = b;
    cout << typeid(r1).name() << ": " << typeid(r2).name() << endl;

    return 0;
}

/*
Output:
1A: P1A
P1A: 1A
1B: P1B
P1A: 1B
1A: 1B

*/