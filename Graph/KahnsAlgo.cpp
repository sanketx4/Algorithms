#include <bits/stdc++.h>
using namespace std;
vector<int> topologicalSort(vector<vector<int>> &graph, int edges, int nodes) {
    vector<int> ans;
    vector<int> indegree(nodes,0);
    vector<int> adj[nodes];
    for(auto it : graph){
        adj[it[0]].push_back(it[1]);
        indegree[it[1]]++;
    }
    queue<int> q;
    for(int i =0;i<nodes;i++){
        if(indegree[i]==0)
        q.push(i);
    }
    while(!q.empty()){
        int node = q.front();
        q.pop();
        ans.push_back(node);
        for(auto it : adj[node]){
            indegree[it]--;
            if(indegree[it]==0)
            q.push(it);
        }
    }
    return ans;
}
