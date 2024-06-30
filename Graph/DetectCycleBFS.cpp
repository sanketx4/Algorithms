#include <bits/stdc++.h>
using namespace std;
bool iscycle(vector<int> adj[],bool vis[],int node){
        queue<pair<int,int>> q;
        q.push({node,-1});
        vis[node]=1;
        while(!q.empty()){
            node=q.front().first;
            int parent=q.front().second;
            q.pop();
            for(auto it:adj[node]){
                if(vis[it]==false){
                    q.push({it,node});
                    vis[it]=1;
                }
                else if(it!=parent)return true;
            }
        }
        return false;
    }
    bool isCycle(int V, vector<int> adj[]) {
        bool vis[V]={false};
        for(int i=0;i<V;i++){
            if(vis[i]==false){
                if(iscycle(adj,vis,i))return true;
            }
        }
        return false;
    }
