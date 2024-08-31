#include <iostream>
#include <queue>
using namespace std;

/*
Queues are a type of container adaptors that operate in a first in first out (FIFO) type
of arrangement.
Elements are inserted at the back (end) and are deleted from the front.
Queues use an encapsulated object of deque or list (sequential container class) as
its underlying container, providing a specific set of member functions to access
its elements.

queue<int> gquiz;
*/

void queue_explanination()
{
    queue<int> q;

    q.push(1);                 // {1}
    q.push(2);                 // {1, 2}
    q.emplace(3);              // {1, 2, 3}
    cout << q.front() << endl; // {1}

    q.back() += 5;            // add 5 to last element ==> (3+5 = 8)
    cout << q.back() << endl; // {8}

    q.pop();                   // delets 1 from queue
    cout << q.front() << endl; // {2}

    cout << q.empty() << endl; // q is not empty: 0
    cout << q.size() << endl;  // size of q
}

int main(void)
{
    queue_explanination();
    return 0;
}