#include <iostream>
#include <cstdlib>
#include <cstring>
using namespace std;

/*
In copy assignment operator, str = s.str (i.e. Shallow Copy) should
not be done for two reasons:
1) Resource held by str will leak
2) Shallow copy will result with its related issues

Deep Copy:
Deep copy allocates new space for the contents and copies
the pointed data

Shallow Copy:
Shallow copy merely copies the pointer value – hence,
the new copy and the original pointer continue to point
to the same data
*/

class String
{
private:
    char *str_;
    size_t len_;

public:
    String(char *s) : str_(strdup(s)), len_(strlen(str_)) // Constructor
    {
        cout << "Ctor" << endl;
    }

    // Copy Constructor
    String(const String &s) : str_(strdup(s.str_)), len_(s.len_)
    {
        cout << "Copy Ctor" << endl;
    }

    ~String() // Destructor
    {
        cout << "Dtor" << endl;
        free(str_);
    }

    String &operator=(const String &s) // Copy Assignment Operator
    {
        free(str_);            // Release existing memory
        str_ = strdup(s.str_); // Perform deep copy
        // str_ = s.str; // Perform shallow copy
        len_ = s.len_;

        cout << "Copy Assignment Operator" << endl;
        return *this; // Return object for chain assignment
    }

    void print()
    {
        cout << "(" << str_ << ": " << len_ << ")" << endl;
    }
};

int main()
{
    String s1 = "Football"; // Constructor
    String s2 = "Cricket";  // Constructor

    s1.print();
    s2.print();
    s2 = s1; // Copy Assignment Operator
    s2.print();

    return 0;
}