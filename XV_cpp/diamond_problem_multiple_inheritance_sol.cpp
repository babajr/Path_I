/*
C++ addresses the Diamond Problem using virtual inheritance.
Virtual inheritance ensures that there is only one instance of the
common base class, eliminating the ambiguity.

1. Virtual Base Class with Defualt Constructor
2. Virtual Base Class with Parameterised Constructor
*/

/*
1. Virtual Base Class with Defualt Constructor
*/

/*
#include <iostream>
using namespace std;

class Person
{ // Data members of person
public:
    Person(int x) { cout << "Person::Person(int)" << endl; }
    Person() { cout << "Person::Person()" << endl; } // Default ctor for virtual inheritance };
};

class Faculty : virtual public Person
{ // data members of Faculty
public:
    Faculty(int x) : Person(x) { cout << "Faculty::Faculty(int)" << endl; }
};

class Student : virtual public Person
{ // data members of Student
public:
    Student(int x) : Person(x) { cout << "Student::Student(int)" << endl; }
};

class TA : public Faculty, public Student
{
public:
    TA(int x) : Student(x), Faculty(x) { cout << "TA::TA(int)" << endl; }
};

int main()
{
    TA ta(30);
    return 0;
}
*/

/*
Introduce a default constructor for root base class Person
Prefix every inheritance of Person with virtual
Only one instance of base class object (Person) in a TA object!

Person::Person()
Faculty::Faculty(int)
Student::Student(int)
TA::TA(int)
*/

/*
2. Virtual Base Class with Parameterised Constructor
*/

#include <iostream>
using namespace std;

class Person
{
public:
    Person(int x) { cout << "Person::Person(int)" << endl; }
    Person() { cout << "Person::Person()" << endl; }
};

class Faculty : virtual public Person
{
public:
    Faculty(int x) : Person(x) { cout << "Faculty::Faculty(int)" << endl; }
};

class Student : virtual public Person
{
public:
    Student(int x) : Person(x) { cout << "Student::Student(int)" << endl; }
};

class TA : public Faculty, public Student
{
public:
    TA(int x) : Student(x), Faculty(x), Person(x)
    { // Call parameterized constructor of root base class Person from
      // constructor of TA class.
        cout << "TA::TA(int)" << endl;
    }
};

int main()
{
    TA ta(30);
    return 0;
}

/*
Introduce a default constructor for root base class Person
Prefix every inheritance of Person with virtual
Only one instance of base class object (Person) in a TA object!
Call parameterized constructor of root base class Person from
constructor of TA class.

Person::Person(int)
Faculty::Faculty(int)
Student::Student(int)
TA::TA(int )
*/