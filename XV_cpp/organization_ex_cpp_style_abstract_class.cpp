#include <iostream>
#include <string>
using namespace std;

class Employee // Abstract Class
{
protected:
    string name_;

public:
    virtual void ProcessSalary() = 0; // Pure Virtual Function
};

class Engineer : public Employee
{
public:
    Engineer(const string &name) { name_ = name; }

    void ProcessSalary()
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

class SalesExecutive : public Employee
{
public:
    SalesExecutive(const string &name)
    {
        name_ = name;
    }

    void ProcessSalary()
    {
        cout << name_ << ": Process Salary for Sales Executive" << endl;
    }
};

int main()
{

    Engineer e1("Rohit"), e2("Kavita"), e3("Shambhu");
    Manager m1("Kamala"), m2("Rajib");
    SalesExecutive s1("Hari"), s2("Bishnu");
    Director d("Ranjana");

    Employee *staff[] = {&e1, &m1, &m2, &e2, &s1, &e3, &d, &s2};

    for (int i = 0; i < sizeof(staff) / sizeof(Employee *); ++i)
        staff[i]->ProcessSalary();

    return 0;
}