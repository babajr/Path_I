#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*******************************************************************************/
/*           Declaration of Staff: Engineer, Manager, Director                 */
/*******************************************************************************/

typedef enum E_TYPE
{
    Er,
    Mgr,
    Dir
} E_TYPE;

typedef struct Engineer
{
    char *name_;
} Engineer;

typedef struct Manager
{
    char *name_;
    Engineer *reports_[10]; // At max 10 engineers will report to Manager
} Manager;

typedef struct Director
{
    char *name_;
    Manager *reports_[10]; // At max 10 Managers will report to Manager
} Director;

typedef struct Staff
{
    E_TYPE type_;
    union
    {
        Engineer *pE;
        Manager *pM;
        Director *pD;
    };
} Staff;

/*******************************************************************************/
/*                              Initialization                                 */
/*******************************************************************************/
Engineer *InitEngineer(const char *name)
{
    Engineer *e = (Engineer *)malloc(sizeof(Engineer));
    e->name_ = strdup(name);
    return e;
}

Manager *InitManager(const char *name)
{
    Manager *m = (Manager *)malloc(sizeof(Manager));
    m->name_ = strdup(name);
    return m;
}

Director *InitDirector(const char *name)
{
    Director *d = (Director *)malloc(sizeof(Director));
    d->name_ = strdup(name);
    return d;
}

void ProcessSalaryEngineer(Engineer *e)
{
    printf("%s: Process Salary for Engineer\n", e->name_);
}

void ProcessSalaryManager(Manager *m)
{
    printf("%s: Process Salary for Manager\n", m->name_);
}

void ProcessSalaryDirector(Director *d)
{
    printf("%s: Process Salary for Director\n", d->name_);
}

/*
Application Code
*/
int main()
{
    Staff allStaff[10];

    allStaff[0].type_ = Er;
    allStaff[0].pE = InitEngineer("Rohit");

    allStaff[1].type_ = Mgr;
    allStaff[1].pM = InitManager("Kamala");

    allStaff[2].type_ = Mgr;
    allStaff[2].pM = InitManager("Rajib");

    allStaff[3].type_ = Er;
    allStaff[3].pE = InitEngineer("Kavita");

    allStaff[4].type_ = Er;
    allStaff[4].pE = InitEngineer("Shambhu");

    allStaff[5].type_ = Dir;
    allStaff[5].pD = InitDirector("Ranjana");

    for (int i = 0; i < 6; ++i)
    {
        E_TYPE t = allStaff[i].type_;

        switch (t)
        {
        case Er:
            ProcessSalaryEngineer(allStaff[i].pE);
            break;
        case Mgr:
            ProcessSalaryManager(allStaff[i].pM);
            break;
        case Dir:
            ProcessSalaryDirector(allStaff[i].pD);
            break;
        Default:
            printf("Invalid Staff. \n");
            break;
        }

        // if (t == Er)
        //     ProcessSalaryEngineer(allStaff[i].pE);
        // else if (t == Mgr)
        //     ProcessSalaryManager(allStaff[i].pM);
        // else if (t == Dir)
        //     ProcessSalaryDirector(allStaff[i].pD);
        // else
        //     printf("Invalid Staff Type\n");
    }
    return 0;
}
