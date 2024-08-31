#include <iostream>
using namespace std;

class A
{
};

class B
{
};

int main()
{
    int i = 2;
    double d = 3.7;
    double *pd = &d;

    i = pd;                        // implicit -- error
    i = reinterpret_cast<int>(pd); // reinterpret_cast -- okay
    i = (int)pd;                   // C-style -- okay
    cout << pd << " " << i << endl;

    A *pA;
    B *pB;
    pA = pB;                        // implicit -- error
    pA = reinterpret_cast<A *>(pB); // reinterpret_cast -- okay
    pA = (A *)pB;                   // C-style -- okay

    return 0;
}