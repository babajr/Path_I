#include "iostream"
using namespace std;
struct Node
{
    struct Node *next;
    int data;
};
Node *head = NULL;

void insert(Node *temp, int data)
{
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = new Node;
    temp = temp->next;
    temp->data = data;
    temp->next = NULL;
}

void display(Node *temp)
{

    while (temp != NULL)
    {
        cout << "   " << temp->data;
        temp = temp->next;
    }
    cout << "\n--------------------------------------\n";
}

Node *merge(Node *temp1, Node *temp2)
{
    if (temp1 == NULL)
        return temp2; // should append remaining temp2 list
    if (temp2 == NULL)
        return temp1; // should append remaining temp1 list
    if (temp1->data < temp2->data)
    {
        temp1->next = merge(temp1->next, temp2);
        return temp1;
    }
    else
    {
        temp2->next = merge(temp1, temp2->next);
        return temp2;
    }
}

// Node *merge_iterative(Node *p, Node *q)
// {
//     Node *last = NULL;
//     Node *third = NULL;

//     if (p->data < q->data)
//     {
//         third = last = p;
//         p = p->next;
//         third->next = NULL;
//     }
//     else
//     {
//         third = last = q;
//         q = q->next;
//         third->next = NULL;
//     }
//     while (p && q)
//     {
//         if (p->data < q->data)
//         {
//             last->next = p;
//             last = p;
//             p = p->next;
//             last->next = NULL;
//         }
//         else
//         {
//             last->next = q;
//             last = q;
//             q = q->next;
//             last->next = NULL;
//         }
//     }
//     if (p)
//         last->next = p;
//     if (q)
//         last->next = q;

//     return third;
// }

Node *merge_iterative(Node *head1, Node *head2)
{
    Node *head3 = NULL;
    Node *last = NULL;

    if (head1->data < head2->data)
    {
        head3 = head1;
        last = head1;
        head1 = head1->next;
        head3->next = NULL;
    }
    else
    {
        head3 = head2;
        last = head2;
        head2 = head2->next;
        head3->next = NULL;
    }

    while (head1 != NULL && head2 != NULL)
    {
        if (head1->data < head2->data)
        {
            last->next = head1;
            last = head1;
            head1 = head1->next;
            last->next = NULL;
        }
        else
        {
            last->next = head2;
            last = head2;
            head2 = head2->next;
            last->next = NULL;
        }
    }

    if (head1 != NULL)
        last->next = head1;
    if (head2 != NULL)
        last->next = head2;

    return head3;
}

int main()
{
    head = new Node;
    head->data = 1;
    head->next = NULL;
    insert(head, 3);
    insert(head, 5);

    cout << "sorted List1" << endl;
    display(head);

    Node *head1 = new Node;
    head1->data = 0;
    head1->next = NULL;
    insert(head1, 2);
    insert(head1, 4);
    insert(head1, 14);
    insert(head1, 98);

    cout << "sorted List2" << endl;
    display(head1);

    // Node *newHead = merge(head, head1);
    // cout << " merged List : " << endl;
    // display(newHead);

    Node *newHead1 = merge_iterative(head, head1);
    cout << " merged List Iterative: " << endl;
    display(newHead1);

    return 0;
}

/*
Output -

sorted List1
   1   3   5
--------------------------------------
sorted List2
   0   2   4   14   98
--------------------------------------
 merged List :
   0   1   2   3   4   5   14   98
--------------------------------------
*/
