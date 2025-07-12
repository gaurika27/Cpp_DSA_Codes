//Using BFS
#include<queue>
bool isCyclicBFS(int i, vector<bool>& visited, vector<vector<int>>& adj) {
    vector<int> parent(adj.size(), -1);
    visited[i] = true;
    queue<int> q;
    q.push(i);

    while (!q.empty()) {
        int front = q.front();
        q.pop();

        for (auto neighbour : adj[front]) {
            if (!visited[neighbour]) {
                q.push(neighbour);
                visited[neighbour] = true;
                parent[neighbour] = front;
            }else if (visited[neighbour]==true && neighbour != parent[front]) {
                return true;
            }
        }
    }
    return false;
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
            if (isCyclicBFS(i, visited, adj)) {
                return "Yes";
            }
        }
    }
    return "No";
}
