// C++ program to illustrate the
// above discussed functionality
#include <cstring>
#include <iostream>
using namespace std;

// Custom string class
class Mystring
{
    // Initialise the char array
    char *str;

public:
    // No arguments Constructor
    Mystring()
    {
        str = new char[1];
        str[0] = '\0';
    }

    // Parameterised Ctor
    Mystring(char *val)
    {
        if (val == nullptr)
        {
            str = new char[1];
            str[0] = '\0';
        }

        else
        {
            str = new char[strlen(val) + 1];

            // Copy character of val[] using strcpy
            strcpy(str, val);
            str[strlen(val)] = '\0';

            cout << "The string passed is: " << str << endl;
        }
    }

    // Copy Constructor
    Mystring(const Mystring &source)
    {
        str = new char[strlen(source.str) + 1];
        strcpy(str, source.str);
        str[strlen(source.str)] = '\0';
    }

    // Move Constructor
    Mystring(Mystring &&source)
    {
        str = source.str;
        source.str = nullptr;
    }

    // Destructor
    ~Mystring() { delete str; }
};

// Driver Code
int main()
{
    // Constructor with no arguments
    Mystring a;

    // Convert string literal to char array
    char temp[] = "Hello";

    // Constructor with one argument
    Mystring b{temp};

    // Copy constructor
    Mystring c{a};

    char temp1[] = "World";

    // One arg constructor called, then the move constructor
    Mystring d{Mystring{temp1}};
    return 0;
}
