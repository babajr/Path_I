/*
Function pointers can be useful when you want to create callback mechanism,
and need to pass address of a function to another function.
*/

#include "iostream"
using namespace std;

void display()
{
    cout << "display()\n";
}

int add(int x, int y)
{
    cout << "add(int, int)\n";
    return x + y;
}

int main()
{
    int (*fun_ptr)(int, int); // return_type (*func_ptr_name) (parameters)

    // fun_ptr is a pointer to function fun()
    fun_ptr = add;           // funcPtr = &add;
    int res = fun_ptr(2, 3); // Function Call
    cout << res << endl;

    // fun_ptr_1 is a pointer to function display()
    void (*fun_ptr_1)();
    fun_ptr_1 = display; // fun_ptr_1 = &display;
    fun_ptr_1();         // // Function Call

    return 0;
}