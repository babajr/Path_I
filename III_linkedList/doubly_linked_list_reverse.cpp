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

void display(Node *ptr)
{
    while (ptr != NULL)
    {
        printf("%d\t", ptr->data);
        ptr = ptr->next;
    }

    printf("\n");
}

/*
h -> 1 -> 2 -> 3 -> N
N <-   <-   <-   <-

*/
void reverse(Node *ptr)
{
    while (ptr != NULL)
    {
        Node *temp = ptr->next;
        ptr->next = ptr->prev;
        ptr->prev = temp;
        ptr = ptr->prev;

        if (ptr != NULL && ptr->next == NULL)
            head = ptr;
    }
}

int main()
{
    insert_at_head(head, 1);
    insert_at_head(head, 2);
    insert_at_head(head, 3);
    insert_at_head(head, 4);
    display(head);

    reverse(head);
    display(head);

    // display_reverse(head);

    return 0;
}