/*
A singleton class is a special type of class in object-oriented programming
which can have only one object or instance at a time. In other words,
we can instantiate only one instance of the singleton class.
The new variable also points to the initial instance created if we
attempt to instantiate the Singleton class after the first time.

Steps to Implement Singleton Class in C++:

-- Make all the constructors of the class private.
-- Delete the copy constructor of the class.
-- Make a private static pointer that can point to the same class object
   (singleton class).
-- Make a public static method that returns the pointer to the same class object
   (singleton class).
*/

// Implementation of Singleton Classin C++
#include <iostream>
using namespace std;

class Singleton
{
private:
    static Singleton *instance;

    // Default constructor
    Singleton()
    {
        cout << "I am in default constructor" << endl;
    }

    ~Singleton()
    {
        cout << "I am in default destructor" << endl;
    }

public:
    // deleting copy constructor (Optional)
    // Singleton(const Singleton &obj) = delete;

    /*
        getInstance() is a static method that returns an
        instance when it is invoked. It returns the same
        instance if it is invoked more than once as an instance
        of Singleton class is already created. It is static
        because we have to invoke this method without any object
        of Singleton class and static method can be invoked
        without object of class

        As constructor is private so we cannot create object of
        Singleton class without a static method as they can be
        called without objects. We have to create an instance of
        this Singleton class by using getInstance() method.
    */
    static Singleton *getInstance()
    {
        // If there is no instance of class then we can create an instance.
        if (instance == NULL)
        {
            // We can access private members within the class.
            instance = new Singleton();

            // returning the instance pointer
            return instance;
        }
        else
        {
            // if instancePtr != NULL that means the class already have an instance.
            // So, we are returning that instance and not creating new one.
            return instance;
        }
    }
};

// initializing instancePtr with NULL
Singleton *Singleton::instance = NULL;

// Driver code
int main()
{
    Singleton *obj1 = Singleton::getInstance();

    Singleton *obj2 = Singleton::getInstance();

    cout << obj1 << endl;
    cout << obj2 << endl;

    return 0;
}
