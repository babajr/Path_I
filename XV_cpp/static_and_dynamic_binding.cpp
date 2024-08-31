#include <iostream>
using namespace std;

class B
{
public:
    void f() { cout << "B::f()" << endl; }
    virtual void g() { cout << "B::g()" << endl; }
};

class D : public B
{
public:
    void f() { cout << "D::f()" << endl; }
    virtual void g() { cout << "D::g()" << endl; }
};

int main()
{
    B b;
    D d;

    B *pb = &b;
    B *pd = &d; // UPCAST

    B &rb = b;
    B &rd = d; // UPCAST

    b.f(); // B::f()
    b.g(); // B::g()
    d.f(); // D::f()
    d.g(); // D::g()

    pb->f(); // B::f() -- Static Binding
    pb->g(); // B::g() -- Dynamic Binding
    pd->f(); // B::f() -- Static Binding
    pd->g(); // D::g() -- Dynamic Binding

    rb.f(); // B::f() -- Static Binding
    rb.g(); // B::g() -- Dynamic Binding
    rd.f(); // B::f() -- Static Binding
    rd.g(); // D::g() -- Dynamic Binding

    return 0;
}