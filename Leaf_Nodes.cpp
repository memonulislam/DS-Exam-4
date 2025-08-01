#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int value;
    Node *left;
    Node *right;

    Node(int value)
    {
        this->value = value;
        this->left = NULL;
        this->right = NULL;
    }
};

Node *input_binary_tree()
{
    int value;
    cin >> value;
    Node *root;
    if (value == -1)
    {
        root = NULL;
    }
    else
    {
        root = new Node(value);
    }
    queue<Node *> q;
    if (root)
    {
        q.push(root);
    }
    while (!q.empty())
    {
        Node *p = q.front();
        q.pop();
        int left_value, right_value;
        cin >> left_value >> right_value;
        Node *myLeft, *myRight;
        if (left_value == -1)
        {
            myLeft = NULL;
        }
        else
        {
            myLeft = new Node(left_value);
        }
        if (right_value == -1)
        {
            myRight = NULL;
        }
        else
        {
            myRight = new Node(right_value);
        }

        p->left = myLeft;
        p->right = myRight;

        if (p->left)
        {
            q.push(p->left);
        }
        if (p->right)
        {
            q.push(p->right);
        }
    }

    return root;
};

void Leaf_Nodes(Node *root, vector<int> &leaf)
{
    if (root == NULL)
        return;

    if (root->left == NULL && root->right == NULL)
    {
        leaf.push_back(root->value);
        return;
    }

    Leaf_Nodes(root->left, leaf);
    Leaf_Nodes(root->right, leaf);
}

int main()
{

    Node *root = input_binary_tree();
    vector<int> leaf;
    Leaf_Nodes(root, leaf);

    sort(leaf.begin(), leaf.end(), greater<int>());

    for (int res : leaf)
    {
        cout << res << " ";
    }
    return 0;
}