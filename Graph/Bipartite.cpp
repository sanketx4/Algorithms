#include <bits/stdc++.h>
using namespace std;

bool dfs(vector<int> adj[], bool vis[], bool pathvis[], int node)
{
    vis[node] = 1;
    pathvis[node] = 1;
    for (auto adjnode : adj[node])
    {
        if (!vis[adjnode])
        {
            if (dfs(adj, vis, pathvis, adjnode))
                return true;
        }
        else if (pathvis[adjnode])
            return true;
    }
    pathvis[node] = 0;
    return false;
}
bool isCyclic(vector<vector<int>> &edges, int v, int e)
{
    bool vis[v] = {0};
    bool pathvis[v] = {0};
    vector<int> adj[v];
    for (auto it : edges)
    {
        adj[it[0]].push_back(it[1]);
    }
    for (int i = 0; i < v; i++)
    {
        if (!vis[i])
        {
            if (dfs(adj, vis, pathvis, i))
                return true;
        }
    }
    return false;
}
