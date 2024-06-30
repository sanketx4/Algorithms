#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
    Node() : data(0), left(nullptr), right(nullptr) {}
    Node(int x) : data(x), left(nullptr), right(nullptr) {}
    Node(int x, Node *left, Node *right) : data(x), left(left), right(right) {}
};

vector<int> topView(Node *root)
{
    vector<int> ans;
    if (root == NULL)
        return ans;
    map<int, int> m;
    queue<pair<Node *, int>> q;

    q.push({root, 0});
    while (!q.empty())
    {
        auto it = q.front();
        int vertical = it.second;
        q.pop();
        if (m.find(vertical) == m.end())
            m[vertical] = it.first->data;
        if (it.first->left)
            q.push({it.first->left, vertical - 1});
        if (it.first->right)
            q.push({it.first->right, vertical + 1});
    }

    for (auto it : m)
        ans.push_back(it.second);
    return ans;
}