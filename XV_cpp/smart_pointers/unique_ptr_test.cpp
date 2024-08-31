#include <iostream>
#include <memory>
using namespace std;

class A
{
public:
    int a;
    A() : a(0) {}
    A(int a_) : a(a_) {}
    ~A() {}
};

/*
1. Pass the smart pointer by reference.
*/
void func(unique_ptr<A> &arg)
{
    cout << "In func:" << arg->a << endl;
}

/*
2. Move the smart pointer into the function argument.
*/
void func_1(unique_ptr<A> arg)
{
    cout << "In func_1:" << arg->a << endl;
}

/*
We can pass a std::unique_ptr into a function.
To pass unique_ptr as argument to function, there are two options:
1. Pass the smart pointer by reference.
2. Move the smart pointer into the function argument.
*/
int main()
{
    unique_ptr<A> ptr(new A(1));
    cout << ptr->a << endl;

    func(ptr);
    func_1(move(ptr));

    return 0;
}