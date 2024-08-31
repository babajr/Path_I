#include <iostream>
#include <cstdlib>
using namespace std;

struct node
{
    int data;
    struct node *next;
};

typedef struct node Node;
Node *head = NULL;

void display(Node *ptr)
{
    while (ptr != NULL)
    {
        cout << ptr->data << " ";
        ptr = ptr->next;
    }

    cout << endl;
}

int count(Node *ptr)
{
    int c = 0;
    while (ptr != NULL)
    {
        c++;
        ptr = ptr->next;
    }

    return c;
}

void insert(Node *ptr, int pos, int data)
{
    // Node *newNode = new Node;
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    if (pos < 0 || pos > count(ptr))
    {
        cout << "Invalid Position: " << pos << endl;
        return;
    }

    if (pos == 0)
    {
        newNode->next = head;
        head = newNode;
    }
    else
    {
        for (int i = 0; i < (pos - 1); i++)
        {
            ptr = ptr->next;
        }

        newNode->next = ptr->next;
        ptr->next = newNode;
    }
}

// 1 Based Position
void delete_node(Node *ptr, int pos)
{
    Node *temp = NULL;

    cout << count(ptr) << endl;
    if (pos < 1 || pos > count(ptr))
    {
        cout << "Invalid Position: " << pos << endl;
        return;
    }

    // Assume 1 based Indexing
    if (pos == 1)
    {
        temp = head;
        head = temp->next;
        free(temp);
    }
    else
    {
        temp = ptr;

        for (int i = 0; i < (pos - 1); i++)
        {
            ptr = temp;
            temp = ptr->next;
        }

        ptr->next = temp->next;
        free(temp);
    }
}

/*
0 Based Position and need to return head node
*/

// Node *deleteNode(Node *ptr, int pos)
// {
//     if (pos < 0 || pos > count(ptr))
//         return ptr;

//     if (pos == 0)
//     {
//         Node *temp = ptr;
//         ptr = ptr->next;
//         free(temp);
//         return ptr;
//     }
//     else
//     {
//         Node *curr = ptr;
//         Node *prev = ptr;

//         for (int i = 0; i < pos; i++)
//         {
//             prev = curr;
//             curr = curr->next;
//         }

//         prev->next = curr->next;
//         free(curr);
//     }

//     return ptr;
// }

int main()
{
    insert(head, 0, 1);
    display(head);
    insert(head, 1, 2);
    display(head);
    insert(head, 2, 3);
    display(head);
    insert(head, 3, 4);
    display(head);

    delete_node(head, 4);
    display(head);

    return 0;
}