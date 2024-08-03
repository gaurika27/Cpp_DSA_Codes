//Using BFS
#include<queue>
bool isCyclicDFS(int i, vector<bool>& visited,int parent, vector<vector<int>>& adj){
  visited[i]=true;
  for(auto neighbour: adj[i]){
    if(!visited[neighbour]){
      bool cycleDetected=isCyclicDFS(neighbour, i, visited, adj)
      if(cycleDetected){
        return true;
      }
      else if(neighbour!=parent){
        return true;
      }
    }
    return false;
  }
}

string cycleDetection(vector<vector<int>>& edges, int n, int m) {
    // Create adjacency list
    vector<vector<int>> adj(n+1);
    for (int i = 0; i < m; ++i) {
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // To handle disconnected components
    vector<bool> visited(n, false);
    for (int i = 0; i < n; ++i) {
        if (!visited[i]) {
            if (isCyclicDFS(i, visited,-1, adj)) {
                return "Yes";
            }
        }
    }
    return "No";
}
