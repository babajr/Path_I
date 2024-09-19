/****************************************************************************
File name: reverse_linkedlist.cpp

Author: babajr
*****************************************************************************/

/*
Given the head of a Singly LinkedList, reverse the LinkedList. Write a function to
return the new head of the reversed LinkedList.

Input: head ->  1   ->  2   ->  3   -> NULL
Output: NULL    <-  1   <-  2   <-  3   <-  head
*/

#include <bits/stdc++.h>
#include <stack>
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
API to insert node always at the last position.
*/
void insertAtLast(Node *ptr, int value)
{
    Node *last = NULL; // pointer to point to last node of list.

    // create new node
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;

    // if list is empty i.e. head or ptr = NULL
    if (ptr == NULL)
    {
        head = newNode;
        last = newNode;
    }
    else
    {
        last = ptr;                // start last pointer from head
        while (last->next != NULL) // traverse the list until last pointer reach to last node of list.
        {
            last = last->next;
        }

        // create the link between last node to the new node and point
        // the last pointer to the new last node.
        last->next = newNode;
        last = newNode;
    }
}

/*
Brute Force: Using stack data structure to temporarily store the values.
-- Create an empty stack. This stack will be used to temporarily store the nodes
   from the original linked list as we traverse it.
-- Push all the elements of list to stack as we traverse the list.
-- Set variable `temp` back to the head of the linked list.
   While the stack is not empty, set the value at the temp node to the value at the
   top of the stack. Pop the stack and move temp to the next node till it reaches null.
*/
Node *reverse_bf(Node *ptr)
{
    // Create a temporary pointer to traverse the linked list
    Node *temp = ptr;

    // Create a stack to temporarily store the data values
    stack<int> st;

    // Step 1: Push the values of the linked list onto the stack
    while (temp != nullptr)
    {
        // Push the current node's data onto the stack
        st.push(temp->data);

        // Move to the next node in the linked list
        temp = temp->next;
    }

    // Reset the temporary pointer to the head of the linked list
    temp = ptr;

    // Step 2: Pop values from the stack and update the linked list
    while (temp != nullptr)
    {
        // Set the current node's data to the value at the top of the stack
        temp->data = st.top();

        // Pop the top element from the stack
        st.pop();

        // Move to the next node in the linked list
        temp = temp->next;
    }

    // Return the new head of the reversed linked list
    return ptr;
}

/*
Recursive Reversal
*/
Node *reverse_recursive(Node *head)
{
    // Base case:
    // If the linked list is empty or has only one node,
    // return the head as it is already reversed.
    if (head == NULL || head->next == NULL)
    {
        return head;
    }

    // Recursive step:
    // Reverse the linked list starting
    // from the second node (head->next).
    Node *newHead = reverse_recursive(head->next);

    // Save a reference to the node following
    // the current 'head' node.
    Node *front = head->next;

    // Make the 'front' node point to the current
    // 'head' node in the reversed order.
    front->next = head;

    // Break the link from the current 'head' node
    // to the 'front' node to avoid cycles.
    head->next = NULL;

    // Return the 'newHead,' which is the new
    // head of the reversed linked list.
    return newHead;
}

/*
In Place Reversal.

Algo:
--> reverse one node at a time.
--> start with a variable curr which will initially be curr = head and a variable
    prev which will point to the previous node that we have processed;
    initially prev = NULL.
--> In a stepwise manner, reverse the current node by pointing it to the
    previous node before moving on to the next node.
    Also, update the prev to always point to the previous node that
    we have processed.
*/
Node *reverse(Node *head)
{
    Node *curr = head; // current node that we will be processing.
    Node *prev = NULL; // previous node that is already processed.
    Node *next = NULL; // used to temporarily store next node.

    while (curr != NULL)
    {
        next = curr->next; // store the next node temporarily.
        curr->next = prev; // reverse the current node.
        prev = curr;       // point prev to curr node before moving to the next node.
        curr = next;       // move to the next node.
    }

    // at the end of the loop curr will be pointing to the NULL and
    // prev will be pointing to the last node.
    // prev will be our new head.
    return prev;
}

int main(void)
{
    // we wil be creating list by inserting elements always at the end.
    insertAtLast(head, 10);
    insertAtLast(head, 20);
    insertAtLast(head, 30);
    insertAtLast(head, 30);
    insertAtLast(head, 20);
    // insertAtLast(head, 80);

    printf("Original Linked List\n");
    display(head);

    printf("Reversed Linked List\n");
    head = reverse(head);
    display(head);

    head = reverse_bf(head);
    display(head);

    head = reverse_recursive(head);
    display(head);

    return 0;
}
