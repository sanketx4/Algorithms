#include <bits/stdc++.h>
using namespace std;

vector<int> dijkstra(int V, vector<vector<int>> adj[], int s)
{
    vector<int> dis(V, INT_MAX);
    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
    pq.push({0, s});

    dis[s] = 0;

    while (!pq.empty())
    {
        int node = pq.top()[1];
        int wt = pq.top()[0];
        pq.pop();

        if (dis[node] < wt)
            continue;

        for (auto it : adj[node])
        {
            int d = it[1];
            int num = it[0];

            if (dis[num] > wt + d)
            {
                pq.push({wt + d, num});
                dis[num] = wt + d;
            }
        }
    }
    return dis;
}
