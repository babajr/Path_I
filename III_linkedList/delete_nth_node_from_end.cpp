/****************************************************************************
File name: delete_nth_node_from_end.cpp

Author: babajr
*****************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
};

typedef struct Node Node;
Node *head = NULL; // global head pointer

/*
API to display contents of the linkedlist using iterative approach.
*/
void display(Node *ptr)
{
    if (ptr == NULL)
    {
        printf("LINKED LIST is EMPTY\n");
        return;
    }

    while (ptr != NULL)
    {
        printf("%d\t", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}

/*
API to count number of nodes in the linked list.
*/
int count(Node *ptr)
{
    int nodeCount = 0;
    while (ptr != NULL)
    {
        nodeCount++;
        ptr = ptr->next;
    }

    return nodeCount;
}

/*
API to insert node at particular position.
*/
void insert(Node *ptr, int pos, int value)
{
    // create new node
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;

    // check for valid position
    if (pos < 0 || pos > count(ptr))
    {
        printf("Enter valid position. Either %d or less than %d\n", 0, count(ptr));
        return;
    }

    // inserting at the start of the list
    if (pos == 0)
    {
        newNode->next = head;
        head = newNode;
    }
    else
    {
        // make the ptr to point previous node of mentioned position.
        for (int i = 0; i < pos - 1; i++)
            ptr = ptr->next;

        // first make the link between new node to next node.
        // Then make link from previous node to new node.
        newNode->next = ptr->next;
        ptr->next = newNode;
    }
}

/*
Brute Force:
API to delete the Nth node from the end of the linked list
*/
Node *delete_nth_node_from_end(Node *ptr, int N)
{
    if (head == NULL)
    {
        return NULL;
    }

    int count_of_nodes = 0;
    Node *temp = ptr;

    // Count the number of nodes in the linked list
    while (temp != NULL)
    {
        count_of_nodes++;
        temp = temp->next;
    }

    if (count_of_nodes < N)
    {
        cout << "Invalid N" << endl;
        return ptr;
    }

    // If N equals the total number of nodes, delete the head.
    // viz. If N = count_of_nodes, delete the head
    if (count_of_nodes == N)
    {
        Node *newhead = ptr;
        head = head->next;
        delete (newhead);
        return head;
    }

    // Calculate the position of the node to delete (res).
    // Traverse upto the node 1 less than the positon of node to be
    // deleted.
    int res_position = count_of_nodes - N;
    temp = ptr;

    // Traverse to the node just before the one to delete
    while (temp != NULL)
    {
        res_position--;
        if (res_position == 0)
        {
            break;
        }
        temp = temp->next;
    }

    // Delete the Nth node from the end
    Node *delNode = temp->next;
    temp->next = temp->next->next;
    delete (delNode);

    return ptr;
}

/*
Efficient Method: Using two pointers
-- Use two pointers : a fast pointer and a slow pointer.
-- The fast-moving pointer will initially be exactly N nodes ahead of
   the slow-moving pointer.
-- After which, both of them will move one step at a time.
   When the fast pointer reaches the last node, i.e., the L-th node,
   the slow is guaranteed to be at the (L-N)-th node,
   where L is the total length of the linked list.
*/
Node *delete_nth_node_from_end_eff(Node *ptr, int N)
{
    // Create two pointers, fast and slow
    Node *fast = ptr;
    Node *slow = ptr;

    // Move the fast pointer N nodes ahead
    for (int i = 0; i < N; i++)
    {
        fast = fast->next;
    }

    // If fast becomes NULL, the Nth node from the end is the head
    if (fast == NULL)
    {
        Node *temp = head;
        head = head->next;
        free(temp);
        // delete (temp);
        return head;
    }

    // Move both pointers until fast reaches the end
    while (fast->next != NULL)
    {
        fast = fast->next;
        slow = slow->next;
    }

    // Delete the Nth node from the end
    Node *delNode = slow->next;
    slow->next = slow->next->next;
    // delete delNode;
    free(delNode);

    return ptr;
}

/* Driver Code */
int main(void)
{
    insert(head, 0, 1);
    insert(head, 1, 2);
    insert(head, 2, 3);
    insert(head, 3, 4);
    insert(head, 3, 5);
    display(head);

    // delete_nth_node_from_end(head, 6);
    // display(head);

    delete_nth_node_from_end_eff(head, 5);
    display(head);

    return 0;
}
