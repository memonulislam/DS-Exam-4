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

bool find_leaf(Node *root)
{
    return root && !root->left && !root->right;
}

void request(Node *root, vector<int> &req)
{
    if (!root)
    {
        return;
    }

    if (root->left || root->right)
    {

        if (root->left)
        {
            request(root->left, req);
        }

        else
        {
            request(root->right, req);
        }

        req.push_back(root->value);
    }
    else
    {

        req.push_back(root->value);
    }
}

void response(Node *root, vector<int> &res)
{
    if (!root)
    {
        return;
    }

    if (root->left || root->right)
    {
        res.push_back(root->value);
        if (root->right)
        {
            response(root->right, res);
        }

        else
        {
            response(root->left, res);
        }
    }
    else
    {
        res.push_back(root->value);
    }
}

int main()
{
    Node *root = input_binary_tree();
    if (!root)
    {
        return 0;
    }

    vector<int> l, r;

    request(root->left, l);

    response(root->right, r);

    for (int ans : l)
    {
        cout << ans << " ";
    }

    cout << root->value << " ";

    for (int ans : r)
    {
        cout << ans << " ";
    }

    cout << endl;
    return 0;
}