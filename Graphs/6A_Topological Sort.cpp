#include <bits/stdc++.h>
#include <vector>
#include <stack> 
void toposort(int node, vector<bool> &visited, stack<int> &st, vector<vector<int>> &adj){
    visited[node]=1;
    for(auto it:adj[node]){
        if(!visited[it]){
            toposort(it, visited, st, adj);
        }
       
    }
     //imp
        st.push(node);
}
vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
    // Write your code here
    vector<vector<int>> adj(v);
    for(int i=0; i<e; i++){
        int u=edges[i][0];
        int v=edges[i][1];
        adj[u].push_back(v);
    }
    //call dfs topological sort util function for all components
    vector<bool> visited(v, 0);
    stack<int> st;
    for(int i=0; i<v; i++){
        if(!visited[i]){
            toposort(i, visited, st, adj);
        }
    }
    vector<int> ans;
    while(!st.empty()){
        ans.push_back(st.top());
        st.pop();
    }
    return ans;
}
