#include <iostream>
#include <list>
using namespace std;

/*
Lists are sequence containers that allow non-contiguous memory allocation.
As compared to the vector, the list has slow traversal, but once a position
has been found, insertion and deletion are quick (constant time).
*/

void list_explanination()
{
    list<int> lst;

    lst.push_back(2);    // {2}
    lst.emplace_back(4); // {2, 4}
    lst.push_front(5);   // {5, 2, 4}

    for (auto it : lst)
    {
        cout << it << " ";
    }

    cout << endl;
}

int main(void)
{
    list_explanination();
    return 0;
}