#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Employee
{
protected:
    string name_; // Name of the employee
    vector<Employee *> reports_;
    // Collection of reportees aggregated
public:
    virtual void ProcessSalary() = 0; // Processing salary

    virtual ~Employee() {} // Virtual Destructor

    static vector<Employee *> staffs; // Collection of all staffs

    void AddStaff(Employee *e) // Add a staff to collection
    {
        staffs.push_back(e);
    }
};

class Engineer : public Employee
{
public:
    Engineer(const string &name)
    {
        name_ = name;
        AddStaff(this);
    }

    void ProcessSalary()
    {
        cout << name_ << ": Process Salary for Engineer" << endl;
    }
};

class Manager : public Engineer
{
public:
    Manager(const string &name) : Engineer(name) {}

    void ProcessSalary()
    {
        cout << name_ << ": Process Salary for Manager" << endl;
    }
};

class Director : public Manager
{
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
        AddStaff(this);
    }

    void ProcessSalary()
    {
        cout << name_ << ": Process Salary for Sales Executive" << endl;
    }
};

vector<Employee *> Employee::staffs; // Collection of all staffs

int main()
{
    Engineer el("Rohit"), e2("Kavita"), e3("Shambhu");
    Manager m1("'Kamala"), m2("Rajib");
    SalesExecutive s1("Hari"), s2("Bishnu");
    Director d("Ranjana");

    vector<Employee *>::const_iterator it; // Iterator over staffs

    for (it = Employee::staffs.begin(); it < Employee::staffs.end(); ++it) // Iterate on staffs
    {
        (*it)->ProcessSalary(); // Process respective salary
    }

    return 0;
}