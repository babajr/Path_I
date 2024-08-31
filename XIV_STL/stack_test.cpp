#include <iostream>
#include <stack>
using namespace std;

/*
Stacks are a type of container adaptors with LIFO(Last In First Out) type of
working, where a new element is added at one end (top) and an element is removed
from that end only.
Stack uses an encapsulated object of either vector or deque (by default) or list
(sequential container class) as its underlying container, providing a specific
set of member functions to access its elements.

stack<int> stack;
*/

void stack_explanination()
{
    stack<int> st;

    st.push(2);               // {2}
    st.push(4);               // {2, 4}
    st.emplace(5);            // {5, 2, 4}
    cout << st.top() << endl; // 5

    // Printing the contents of Stack
    while (st.empty() != true)
    {
        cout << st.top() << " ";
        st.pop();
    }

    cout << endl;
    cout << st.empty() << endl;
}

int main(void)
{
    stack_explanination();
    return 0;
}