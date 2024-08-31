#include <iostream>
#include <string>
using namespace std;

class Engineer
{
protected:
    string name_;

public:
    Engineer(const string &name) : name_(name) {}

    virtual void ProcessSalary() // Polymorphic Hierarachy
    {
        cout << name_ << ": Process Salary for Engineer" << endl;
    }
};

class Manager : public Engineer
{
    Engineer *reports_[10];

public:
    Manager(const string &name) : Engineer(name) {}

    void ProcessSalary()
    {
        cout << name_ << ": Process Salary for Manager" << endl;
    }
};

class Director : public Manager
{
    Manager *reports_[10];

public:
    Director(const string &name) : Manager(name) {}
    void ProcessSalary()
    {
        cout << name_ << ": Process Salary for Director" << endl;
    }
};

/*
Application Code
*/
int main()
{
    Engineer e1("Rohit"), e2("Kavita"), e3("Shambhu");
    Manager m1("Kamala"), m2("Rajib");
    Director d("Ranjana");

    Engineer *staff[] = {&e1, &m1, &m2, &e2, &e3, &d};

    for (int i = 0; i < sizeof(staff) / sizeof(Engineer *); ++i)
    {
        staff[i]->ProcessSalary();
    }

    return 0;
}