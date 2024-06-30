#include <bits/stdc++.h>
using namespace std;

void dfs(vector<int> adj[], vector<int> &ans, vector<int> &vis, int node)
{
    vis[node] = 1;
    ans.push_back(node);
    for (auto it : adj[node])
    {
        if (vis[it] == 0)
        {
            dfs(adj, ans, vis, it);
        }
    }
}

vector<int> dfsOfGraph(int V, vector<int> adj[])
{
    vector<int> ans;
    vector<int> vis(V, 0);
    dfs(adj, ans, vis, 0);
    return ans;
}