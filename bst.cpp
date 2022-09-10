#include "iostream"

using namespace std;

class Node
{
public:
    int val;
    Node *left;
    Node *right;

    Node(int val)
    {
        this->val = val;
        this->left = NULL;
        this->right = NULL;
    }
};

void inOrderTraversal(Node *root)
{
    if (root == NULL)
        return;

    inOrderTraversal(root->left);
    cout << root->val << " ";
    inOrderTraversal(root->right);
}

Node *insertionBST(Node *root, int val)
{
    Node *nw = new Node(val);

    if (root == NULL)
    {
        root = nw;
        return root;
    }

    if (val < root->val) // val < root->val
    {
        root->left = insertionBST(root->left, val);
    }
    else if (val > root->val) // val > root->val
    {
        root->right = insertionBST(root->right, val);
    }

    return root;
}

int main(void)
{
    int n;
    cin >> n;

    Node *root = NULL;

    for (int i = 0; i < n; i++)
    {
        int val;
        cin >> val;

        root = insertionBST(root, val);
    }
    inOrderTraversal(root);
}

/*
9
11 5 9 43 34 1 2 7 21
*/