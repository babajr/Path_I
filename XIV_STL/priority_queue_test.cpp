#include <iostream>
#include <queue>
using namespace std;

/*
A C++ priority queue is a type of container adapter, specifically designed such that
the first element of the queue is either the greatest or the smallest of all elements
in the queue, and elements are in non-increasing or non-decreasing order
(hence we can see that each element of the queue has a priority {fixed order}).

In C++ STL, the top element is always the greatest by default. We can also change
it to the smallest element at the top. Priority queues are built on the top of the
max heap and use an array or vector as an internal structure.
In simple terms, STL Priority Queue is the implementation of Heap Data Structure.

priority_queue<int> pq;
*/

void priority_queue_explanination()
{
    priority_queue<int> q; // Values stored in Desceding order
    // In C++ STL, the top element is always the greatest by default
    // i.e. Max Heap

    q.push(1);               // {1} --> log(n)
    q.push(8);               // {8, 1} Highest value be at the top
    q.emplace(3);            // {8, 3, 1}
    cout << q.top() << endl; // {8} --> O(1)

    q.pop();                 // delets 8 from queue  --> log(n)
    cout << q.top() << endl; // {3}

    cout << q.empty() << endl; // q is not empty: 0
    cout << q.size() << endl;  // size of q

    // If you want to have Minimum element at the top, use Min_heap as shown below.
    priority_queue<int, vector<int>, greater<int>> pq;

    pq.push(5); // {5}
    pq.push(2); // {2, 5}
    pq.push(8); // {2, 5, 8}

    cout << pq.top() << endl; // 2
}

int main(void)
{
    priority_queue_explanination();
    return 0;
}