#include <iostream>
#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *prev;
    struct node *next;
} Node;

Node *head = NULL;

Node *get_new_node(Node *ptr, int val)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = val;
    newNode->prev = NULL;
    newNode->next = NULL;

    return newNode;
}

void insert_at_head(Node *ptr, int val)
{
    Node *newNode = get_new_node(ptr, val);

    // list is empty
    if (ptr == NULL)
    {
        head = newNode;
        return;
    }

    // create prev link from head to newNode
    // create link from newNode's next ot head
    // make newNode as new head
    head->prev = newNode;
    newNode->next = head;
    head = newNode;
}

void insert_at_tail(Node *ptr, int val)
{
    Node *newNode = get_new_node(ptr, val);
    Node *temp = ptr;

    // list is empty
    if (ptr == NULL)
    {
        head = newNode;
        return;
    }

    // traverse the list upto last node using temp pointer
    // create link from temp's next to newNode
    // create link from newNode's prev to temp
    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = newNode;
    newNode->prev = temp;
}

// int count(Node *ptr)
// {
//     Node *temp = ptr;
//     int cnt = 0;

//     do
//     {
//         cnt++;
//         temp = temp->next;
//     } while (temp != NULL);

//     return cnt;
// }

void insert_at_pos(Node *ptr, int val, int pos)
{
    Node *newNode = get_new_node(ptr, val);

    // if (pos < 0 || pos > count(ptr))
    // {
    //     printf("Invalid Position\n");
    //     return;
    // }

    if (pos == 0) // Special case
    {
        if (ptr == NULL) // List is empty
        {
            head = newNode;
            return;
        }

        ptr->prev = newNode;
        newNode->next = ptr;
        head = newNode;
    }
    else
    {
        Node *temp = ptr;

        for (int i = 0; i < (pos - 1); i++)
        {
            temp = temp->next;
        }

        newNode->prev = temp;
        newNode->next = temp->next;

        // If temp was not the last node
        if (temp->next != NULL)
            temp->next->prev = newNode;

        temp->next = newNode;
    }
}

void display(Node *ptr)
{
    while (ptr != NULL)
    {
        printf("%d\t", ptr->data);
        ptr = ptr->next;
    }

    printf("\n");
}

void display_reverse(Node *ptr)
{
    if (ptr == NULL)
    {
        printf("Empty List\n");
        return;
    }

    // Go to the last node
    while (ptr->next != NULL)
        ptr = ptr->next;

    // print in reverse order using prev pointer
    while (ptr != NULL)
    {
        printf("%d\t", ptr->data);
        ptr = ptr->prev;
    }

    printf("\n");
}

void delete_node(Node *ptr, int pos)
{
    Node *temp = ptr;

    if (pos < 1 || pos > count(ptr))
    {
        printf("Invalid Position\n");
        return;
    }

    if (pos == 1)
    {
        head = head->next;
        free(temp);

        // Check if head really exists
        if (head != NULL)
            head->prev = NULL;
    }
    else
    {
        // deleting using single pointer
        // temp will point to the node which we want to
        // delete.
        for (int i = 0; i < (pos - 1); i++)
            temp = temp->next;

        /*       t
        h->1->2->3->4->N
        create a link between 2 and 4.
        temp->prev->next = temp->next;

        create link between 4 and 2.
        temp->next->prev = temp->prev;
        */
        temp->prev->next = temp->next;
        if (temp->next != NULL)
            temp->next->prev = temp->prev;

        free(temp);
    }
}

int main()
{
    // insert_at_head(head, 1);
    // insert_at_head(head, 2);
    // insert_at_head(head, 3);
    // insert_at_head(head, 4);
    // display(head);

    // insert_at_tail(head, 5);
    // display(head);

    insert_at_pos(head, 1, 0); // insert_at_pos(Node *ptr, int val, int pos)
    insert_at_pos(head, 2, 1);
    insert_at_pos(head, 3, 2);
    insert_at_pos(head, 4, 3);
    display(head);

    // delete_node(head, 5);
    // display(head);

    // display_reverse(head);

    return 0;
}