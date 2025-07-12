/*
Steps for Kahn's Algorithm
1) Find indegree of all nodes where indegree:the number of incoming edges to that node.
2) make a queue and insert all the nodes which have 0 indegree in that queue.
3) Do BFS:
       (I) make the front most element of queue as 'front'
       (II) pop out the 'front', i.e, q.pop()
       (III) ans.push_back(front)
       (IV) check front's neighbours in adj list, mark them visited and reduce their indegree by 1
       (V) if any neighbour's indegree become 0; start from (II) by adding that neighbour to the queue and doing the step (III) and its sub steps.
4) Return ans        
*/

#include <bits/stdc++.h> 
vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
    // create adj list
    vector<vector<int>> adj(v);
    for(int i=0; i<e; i++){
        int u=edges[i][0];
        int v=edges[i][1];
        adj[u].push_back(v);
    }
    //find all indegrees
    vector<int> indegree(v, 0); // Initialize all indegrees to 0
    for (auto& neighbors : adj) {
        for (int neighbor : neighbors) {
            indegree[neighbor]++;
        }
    }
    //0 indegree walo ko push kardo
    queue<int> q;
    for(int i=0; i<v; i++){
        if(indegree[i]==0){
            q.push(i);
        }
    }
    //do bfs
    vector<int> ans;
    while(!q.empty()){
        int front=q.front();
        q.pop();

        //ans store
        ans.push_back(front);

        //neighbour indegree update
        for(auto neighbour: adj[front]){
            indegree[neighbour]--;
            if(indegree[neighbour]==0){
                q.push(neighbour);
            }
        }
    }
    return ans;
}
