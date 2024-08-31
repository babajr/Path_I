#include <iostream>
using namespace std;

class A
{
public:
    void f() { cout << "A::f()" << endl; }         // Non Virtual
    virtual void g() { cout << "A::g()" << endl; } //  Virtual
    void h() { cout << "A::h()" << endl; }         // Non Virtual
};

class B : public A
{
public:
    void f() { cout << "B::f()" << endl; }         // Non Virtual
    void g() { cout << "B::g()" << endl; }         // Virtual
    virtual void h() { cout << "B::h()" << endl; } // Virtual
};

class C : public B
{
public:
    void f() { cout << "C::f()" << endl; } // Non Virtual
    void g() { cout << "C::g()" << endl; } // Virtual
    void h() { cout << "C::h()" << endl; } // Virtual
};

int main()
{
    B *q = new C;
    A *p = q;

    p->f(); // A::f()
    p->g(); // C::g()
    p->h(); // A::h()

    q->f(); // B::f()
    q->g(); // C::g()
    q->h(); // C::h()

    return 0;
}
