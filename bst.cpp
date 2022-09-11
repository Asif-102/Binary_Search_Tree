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

Node *searchBST(Node *root, int val)
{
    if (root == NULL)
        return NULL;

    if (root->val == val)
    {
        cout << root->val;
        return root;
    }

    else if (val < root->val)
    {
        cout << root->val << "->";
        searchBST(root->left, val);
    }
    else if (val > root->val)
    {
        cout << root->val << "->";
        searchBST(root->right, val);
    }
}

Node *inorderSuccessor(Node *root)
{
    Node *current = root;

    while(current->left != NULL)
    {
        current = current->left;
    }
    return current;
}

Node *deletionBST(Node *root, int val)
{
    if(val < root->val)
    {
        root->left = deletionBST(root->left, val);
    }
    else if(val > root->val)
    {
        root->right = deletionBST(root->right, val);
    }
    else
    {
        //Implementation of 3 case
        if(root->left == NULL) // CASE 1 -> just delete leaf node | CASE 2 -> If Delete node have only one child
        {
            Node *tmp = root->right;
            free(root);
            return tmp;
        }
        else if(root->right == NULL) // CASE 2 -> If Delete node have only one child
        {
            Node *tmp = root->left;
            free(root);
            return tmp;
        }
        else // CASE 3 -> If delete node have two child
        {
            Node *tmp = inorderSuccessor(root->right);
            root->val = tmp->val;
            root->right = deletionBST(root->right, tmp->val);
        }
        return root;
    }
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
    cout << endl;

    int key;
    cin >> key;

    if(searchBST(root, key) == NULL)
    {
        cout << "\n Value does not exits in the BST";
    }
    else
    {
        cout << "\n Value exits in the BST";
    }
}

/*
9
11 5 9 43 34 1 2 7 21
*/