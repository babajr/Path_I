/*
In C++, inheritance is the concept that allows one class to inherit the
properties and methods of another class.
Multiple inheritance is one such type of inheritance that allows a class
to inherit from more than one base class.
While this feature provides greater flexibility in modelling real-world
relationships, it also introduces complexities, one of which is the
Diamond Problem.

The Diamond Problem is an ambiguity error that arises in multiple
inheritance when a derived class inherits from two or more base classes
that share a common ancestor.
This results in the inheritance hierarchy forming a diamond shape,
hence the name “Diamond Problem.”
The ambiguity arises because the derived class has multiple paths to
access members or methods inherited from the common ancestor,
leading to confusion during method resolution and member access.
*/

#include <iostream>
using namespace std;

class Person
{ // Data members of person
public:
    Person(int x) { cout << "Person::Person(int)" << endl; }
};

class Faculty : public Person
{ // data members of Faculty
public:
    Faculty(int x) : Person(x) { cout << "Faculty::Faculty(int)" << endl; }
};

class Student : public Person
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

/*
Two instances of base class object (Person) in a TA object!

Person::Person(int)
Faculty::Faculty(int)
Person::Person(int)
Student::Student(int)
TA::TA(int)
*/