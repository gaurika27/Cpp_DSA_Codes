void dfs(int i, vector<vector<int>> &adj, vector<int> &store, vector<bool> &visited){
    visited[i]=1;
    store.push_back(i);
    for(auto it: adj[i]){
        if(!visited[it]){
            dfs(it, adj, store, visited);
        }
    }
}
vector<vector<int>> depthFirstSearch(int V, int E, vector<vector<int>> &edges)
{
    vector<vector<int>> adj(V);
    for(int i=0; i<E; ++i){
        int u=edges[i][0];
        int v=edges[i][1];
        adj[u].push_back(v);
        adj[v].push_back(u);        
    }
    vector<vector<int>> ans;
    vector<bool> visited(V, 0);
    for(int i=0; i<V; ++i){
        if(!visited[i]){
            vector<int> store;
            dfs(i, adj, store, visited);
            ans.push_back(store);
        }
    }
    return ans;
    // Write your code here
}
