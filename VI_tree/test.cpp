#include <iostream>
#include <stdlib.h>
using namespace std;

typedef struct node
{
    struct node *left;
    int data;
    struct node *right;
} Node;

Node *root = NULL;

Node *get_new_node(int val)
{
    Node *ptr = new Node;
    //  Node *ptr = (Node *)malloc(Node);
    ptr->left = NULL;
    ptr->data = val;
    ptr->right = NULL;

    return ptr;
}

Node *insert(Node *ptr, int val)
{
    if (ptr == NULL)
    {
        ptr = get_new_node(val);
    }
    else if (ptr->data > val)
        ptr->left = insert(ptr->left, val);
    else
        ptr->right = insert(ptr->right, val);

    return ptr;
}

void print_preorder(Node *ptr)
{
    if (ptr == NULL)
        return;

    cout << ptr->data << " ";
    print_preorder(ptr->left);
    print_preorder(ptr->right);
}

void print_inorder(Node *ptr)
{
    if (ptr == NULL)
        return;

    print_inorder(ptr->left);
    cout << ptr->data << " ";
    print_inorder(ptr->right);
}

void print_postorder(Node *ptr)
{
    if (ptr == NULL)
        return;

    print_postorder(ptr->left);
    print_postorder(ptr->right);
    cout << ptr->data << " ";
}

int count(Node *ptr)
{
    if (ptr == NULL)
        return 0;

    int x = count(ptr->left);
    int y = count(ptr->right);

    return (x + y + 1);
}

int sum_of_nodes(Node *ptr)
{
    if (ptr == NULL)
        return 0;

    int x = sum_of_nodes(ptr->left);
    int y = sum_of_nodes(ptr->right);

    return (x + y + ptr->data);
}

Node *search_bst(Node *ptr, int val)
{
    if (ptr == NULL)
        return NULL;

    if (val == ptr->data)
        return ptr;
    else if (val < ptr->data)
        return search_bst(ptr->left, val);
    else
        return search_bst(ptr->right, val);
}

Node *search_bst_it(Node *ptr, int val)
{
    while (ptr != NULL)
    {
        if (ptr->data == val)
            return ptr;
        else if (val < ptr->data)
            ptr = ptr->left;
        else
            ptr = ptr->right;
    }

    return NULL;
}

int main()
{
    root = insert(root, 30); // create the root node.
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 50);
    root = insert(root, 10);
    root = insert(root, 25);
    root = insert(root, 35);

    print_preorder(root);
    cout << endl;
    print_inorder(root);
    cout << endl;
    print_postorder(root);
    cout << endl;

    cout << "Count of Nodes: " << count(root) << endl;
    cout << "Sum of Nodes: " << sum_of_nodes(root) << endl;

    if (search_bst(root, 100) != NULL)
        cout << "Found" << endl;
    else
        cout << "Not Found" << endl;

    if (search_bst_it(root, 100) != NULL)
        cout << "Found" << endl;
    else
        cout << "Not Found" << endl;

    return 0;
}

/*
                30
        20              40

    10      25      35      50
*/
