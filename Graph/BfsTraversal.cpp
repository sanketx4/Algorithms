#include <bits/stdc++.h>
using namespace std;
vector<int> bfsOfGraph(int V, vector<int> adj[])
{
    vector<int> vis(V, 0);
    vector<int> bfs;
    queue<int> q;
    q.push(0);
    vis[0] = 1;
    while (!q.empty())
    {
        int node = q.front();
        bfs.push_back(node);
        q.pop();
        for (auto it : adj[node])
        {
            if (vis[it] == 0)
            {
                q.push(it);
                vis[it] = 1;
            }
        }
    }
    return bfs;
}