/*
Non Working Code.
*/

#include <iostream>
#include <queue>

using namespace std;

typedef struct treenode
{
    struct treenode *left;
    int data;
    struct treenode *right;
} TreeNode;

TreeNode *root = NULL;

/*
Create Tree using Queue
*/
void create_tree(TreeNode *ptr)
{
    int val;
    TreeNode *curr = NULL;
    TreeNode *temp = NULL;

    // Create Queue
    queue<TreeNode *> q;

    // Create Root Node
    root = new TreeNode;
    // root = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    cout << "Enter root data: " << endl;
    cin >> val;

    root->left = NULL;
    root->data = val;
    root->right = NULL;

    // 1. Insert the root node into Q
    q.emplace(root);

    // 2. Check if Q is empty
    while (!q.empty())
    {
        // Point curr pointer to root of tree/subtree
        // Remove root of tree/subtree from Q
        curr = q.front();
        q.pop();

        cout << "Enter left child data of " << curr->data << ": " << cout;
        cin >> val;

        // For valid value entered by user for Left side node,
        // -- Create temp node and assign val to it.
        // -- Link curr root to left node i.e. temp node
        if (val != -1)
        {
            temp = new TreeNode;
            temp->data = val;
            temp->left = nullptr;
            temp->right = nullptr;
            curr->left = temp;
            q.emplace(temp);
        }

        cout << "Enter right child data of " << curr->data << ": " << flush;
        cin >> val;

        // For valid value entered by user for Right side node,
        // -- Create temp node and assign val to it.
        // -- Link curr root to right node i.e. temp node
        if (val != -1)
        {
            temp = new TreeNode;
            temp->data = val;
            temp->left = nullptr;
            temp->right = nullptr;
            curr->right = temp;
            q.emplace(temp);
        }
    }
}

/*
API to display the tree in PREORDER fashion.
*/
void print_preorder(TreeNode *ptr)
{
    // Tree is empty.
    if (ptr == NULL)
        return;

    printf("%d -> ", ptr->data);
    print_preorder(ptr->left);
    print_preorder(ptr->right);
}

int main()
{
    create_tree(root);
    print_preorder(root);

    return 0;
}