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

void Level_Node(Node *root, int val)
{
    if (root == NULL)
    {
        cout << "Invalid" << endl;
        return;
    }

    queue<pair<Node *, int>> que;
    que.push({root, 0});
    int found = 0;

    while (!que.empty())
    {
        Node *newNode = que.front().first;
        int temp = que.front().second;
        que.pop();

        if (temp == val)
        {
            cout << newNode->value << " ";
            found = 1;
        }

        if (temp > val)
            break;

        if (newNode->left)
        {
            que.push({newNode->left, temp + 1});
        }
        if (newNode->right)
        {
            que.push({newNode->right, temp + 1});
        }
    }

    if (!found)
    {
        cout << "Invalid";
    }
    else
    {
        cout << endl;
    }
}

int main()
{
    Node *root = input_binary_tree();
    int val;
    cin >> val;
    Level_Node(root, val);
    return 0;
}