/****************************************************************************
File name: sort_linkedlist.cpp

Author: babajr
*****************************************************************************/

#include <iostream>
#include <stdlib.h>
#include <vector>
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
TC = O(n) + O(n log n) + O(n)
SC = O(n)
API to sort the linkedlist, using vector.
*/
Node *sort_list_bf(Node *ptr)
{
    // Create a vector to store node values
    vector<int> arr;

    // Temporary pointer to traverse the linked list
    Node *temp = ptr;

    // Traverse the linked list and store node values in the vector
    while (temp != NULL)
    {
        arr.push_back(temp->data);
        temp = temp->next;
    }

    // Sort the array containing node values
    sort(arr.begin(), arr.end());

    // Reassign sorted values to the linked list nodes
    temp = ptr;
    for (int i = 0; i < arr.size(); i++)
    {
        // Update the node's data with the sorted values
        temp->data = arr[i];
        // Move to the next node
        temp = temp->next;
    }

    // Return the head of the sorted linked list
    return ptr;
}

/*
Optimal: Using Merge Sort
*/
Node *merge_two_sorted_lists(Node *list1, Node *list2)
{
    // Create a dummy node to serve as the head of the merged list
    Node *dummyNode = (Node *)malloc(sizeof(Node));
    dummyNode->data = -1;
    dummyNode->next = NULL;

    Node *temp = dummyNode;

    // Traverse both lists simultaneously
    while (list1 != nullptr && list2 != nullptr)
    {
        // Compare elements of both lists and
        // link the smaller node to the merged list
        if (list1->data <= list2->data)
        {
            temp->next = list1;
            list1 = list1->next;
        }
        else
        {
            temp->next = list2;
            list2 = list2->next;
        }
        // Move the temporary pointer
        // to the next node
        temp = temp->next;
    }

    // If any list still has remaining
    // elements, append them to the merged list
    if (list1 != nullptr)
    {
        temp->next = list1;
    }
    else
    {
        temp->next = list2;
    }
    // Return the merged list starting
    // from the next of the dummy node
    return dummyNode->next;
}

// Function to find the middle of a linked list
Node *get_middle(Node *head)
{
    // If the list is empty or has only one node
    // the middle is the head itself
    if (head == nullptr || head->next == nullptr)
    {
        return head;
    }

    // Initializing slow and fast pointers
    Node *slow = head;
    Node *fast = head->next;

    // Move the fast pointer twice as fast as the slow pointer
    // When the fast pointer reaches the end, the slow pointer
    // will be at the middle
    while (fast != nullptr && fast->next != nullptr)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}

// Function to perform merge sort on a linked list
Node *sort_list(Node *head)
{
    // Base case: if the list is empty or has only one node
    // it is already sorted, so return the head
    if (head == nullptr || head->next == nullptr)
    {
        return head;
    }

    // Find the middle of the list using the findMiddle function
    Node *middle = get_middle(head);

    // Divide the list into two halves
    Node *right = middle->next;
    middle->next = nullptr;
    Node *left = head;

    // Recursively sort the left and right halves
    left = sort_list(left);
    right = sort_list(right);

    // Merge the sorted halves using the merge_two_sorted_lists()
    return merge_two_sorted_lists(left, right);
}

/* Driver Code */
int main(void)
{
    insert(head, 0, 1);
    insert(head, 1, 4);
    insert(head, 2, 2);
    insert(head, 3, 3);
    insert(head, 3, 5);
    display(head);

    // Node *res = sort_list_bf(head);
    // display(head);

    Node *res1 = sort_list(head);
    display(head);

    return 0;
}
