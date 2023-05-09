#include <iostream>
using namespace std;
// 210467A
struct node
{
    int key;
    struct node *left, *right;
};

// Inorder traversal
void traverseInOrder(struct node *root)
{

    if (root != nullptr)
    {
        traverseInOrder(root->left);
        cout << root->key << " ";
        traverseInOrder(root->right);
    }
}

// Insert a node
struct node *insertNode(struct node *node, int key)
{
    if (node == nullptr)
    {
        struct node *temp = (struct node *)malloc(sizeof(struct node));
        temp->key = key;
        temp->left = nullptr;
        temp->right = nullptr;
        return temp;
    }
    else if (key < node->key)
    {
        node->left = insertNode(node->left, key);
    }
    else if (key > node->key)
    {
        node->right = insertNode(node->right, key);
    }
    return node;
}

// Deleting a node
struct node *deleteNode(struct node *root, int key)
{
    if (root == NULL)
    {
        return root;
    }
    else if (root->key < key)
    {
        root->left = deleteNode(root->left, key);
    }
    else if (root->key > key)
    {
        root->right = deleteNode(root->right, key);
    }
    else
    {
        if (root->right == nullptr)
        {
            node *temp = root->left;
            delete (root);
            return temp;
        }
        else if (root->left == nullptr)
        {
            node *temp = root->right;
            delete (root);
            return temp;
        }
        node *temp = root->left;
        while (temp->right != nullptr)
        {
            temp = temp->right;
        }
        root->key = temp->key;
        root->right = deleteNode(root->left, temp->key);
    }
    return root;
}
// Driver code
int main()
{
    struct node *root = NULL;

    int operation;
    int operand;
    cin >> operation;

    while (operation != -1)
    {
        switch (operation)
        {
        case 1: // insert
            cin >> operand;
            root = insertNode(root, operand);
            cin >> operation;
            break;
        case 2: // delete
            cin >> operand;
            root = deleteNode(root, operand);
            cin >> operation;
            break;
        default:
            cout << "Invalid Operator!\n";
            return 0;
        }
    }

    traverseInOrder(root);
}
