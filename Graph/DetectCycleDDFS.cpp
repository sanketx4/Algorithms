#include <bits/stdc++.h>
using namespace std;

bool iscycle(vector<int> adj[], bool vis[], int node, int parent)
{
    vis[node] = 1;
    for (auto it : adj[node])
    {
        if (vis[it] == 0)
        {
            if (iscycle(adj, vis, it, node))
                return true;
        }
        else if (it != parent)
            return true;
    }
    return false;
}
bool isCycle(int V, vector<int> adj[])
{
    bool vis[V] = {false};
    for (int i = 0; i < V; i++)
    {
        if (vis[i] == false)
        {
            if (iscycle(adj, vis, i, -1))
                return true;
        }
    }
    return false;
}
