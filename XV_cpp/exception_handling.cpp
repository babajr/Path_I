#include <iostream>
#include <exception>

using namespace std;

class My_excp : public exception
{
};

class A
{
};

void f()
{
    A a; // Object of Class A created

    bool error = true;

    cout << "f() started\n";
    if (error == true)
        throw My_excp(); // 2. Exception raised
                         // 3. Stack frame of f() unwinds and Destructor of
                         //    object a is called.

    cout << "f() ended\n"; // 4. Remaining execution of f() is skipped
}

int main()
{
    try
    {
        cout << "f() called\n";
        f(); // 1. f() called
        cout << "f() returned\n";
    }
    catch (My_excp &) // 5. Exception caught by catch clause
    {
        cout << "f() failed\n";
    }

    cout << "main() exiting\n"; // 6. Normal Flow continues
    return 0;
}