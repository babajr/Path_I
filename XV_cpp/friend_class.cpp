/*
A friend class of a class
-- has access to the private and protected members of the class (breaks the encapsulation)
-- does not have its name qualified with the class scope (not a nested class)
-- can be declared friend in more then one classes

A friend class can be a
-- class
-- class template
*/

/*
List class is now a friend of Node class.
Hence it has full visibility into the internals of Node.

When multiple member functions need to be friends, it is better to use friend class.
*/

#include <iostream>
using namespace std;

class Node; // Forward declaration

class List
{
    Node *head; // Head of the list
    Node *tail; // Tail of the list
public:
    List(Node *h = 0) : head(h), tail(h)
    {
        cout << "List: Ctor" << endl;
    }

    void display();
    void append(Node *p);
};

class Node
{
    int data;   // Data of the node
    Node *next; // Ptr to next node

public:
    Node(int i) : data(i), next(0)
    {
        cout << "List: Ctor" << endl;
    }
    // friend void List::display();
    // friend void List::append(Node *);
    friend class List;
};

void List::display()
{
    Node *ptr = head;
    while (ptr)
    {
        cout << ptr->data << " ";
        ptr = ptr->next;
    }

    cout << endl;
}

void List::append(Node *p)
{
    if (!head)
        head = tail = p;
    else
    {
        tail->next = p;
        tail = tail->next;
    }
}

int main()
{
    List ll; // Empty List
    Node n1(1), n2(2), n3(3);
    ll.append(&n1);
    ll.append(&n2);
    ll.append(&n3);

    ll.display();

    return 0;
}