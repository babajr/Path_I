/*
Templates are specifications of a collection of functions or classes which are
parameterized by types

A template is a simple yet very powerful tool in C++.
The simple idea is to pass the data type as a parameter so that we don’t
need to write the same code for different data types.

Templates are expanded at compiler time.
This is like macros. The difference is, that the compiler does
type-checking before template expansion.

The idea is simple, source code contains only function/class,
but compiled code may contain multiple copies of the same function/class.
*/

/*
Function Template
*/

// #include <iostream>
// using namespace std;

// // One function works for all data types. This would work
// // even for user defined types if operator '>' is overloaded
// template <typename T>
// // template <class T>
// T find_max(T x, T y)
// {
//     return (x > y) ? x : y;
// }

// int main()
// {
//     // Call find_max for int
//     cout << find_max<int>(3, 7) << endl;

//     // call find_max for double
//     cout << find_max<double>(3.0, 7.0) << endl;

//     // call find_max for char
//     cout << find_max<char>('g', 'e') << endl;

//     return 0;
// }

/*
Class Templates
Class templates like function templates, class templates are useful
when a class defines something that is independent of the data type.

-- A class template describes how a class should be built
-- It Supplies the class description and the definition of the member
   functions using some arbitrary type name, (as a place holder)
--


*/

#include "iostream"
using namespace std;

// template class
template <class T>
class Myclass
{
public:
    T a;
    Myclass()
    {
    }
    Myclass(T d)
    {
        this->a = d;
    }
};

// template function can be overload
template <class T>
T add(T a, T b)
{
    cout << " add the same type of data " << endl;
    return (a + b);
}

template <class T, class T1>
T1 add(T a, T1 b)
{
    cout << " add the different type of data " << endl;
    return a + b;
}

int main()
{
    cout << add(2, 3) << endl;   // template function
    cout << add(2, 3.3) << endl; // template function

    // template class object creation
    Myclass<int> a1;
    cout << a1.a << endl;

    Myclass<int> a2(2);
    cout << a2.a << endl;
}