/*
//Intuition
the intuition is to find the ordering in which the nodes are connected in a directed acyclic graph. For this, we will use a slightly modified version of BFS where we will be requiring a queue data structure(First In First Out data structure) and an array that will store the indegree of each node. The indegree of a node is the number of directed edges incoming towards it.
*/
/*
//Initial Configuration:

Indegree Array: Initially all elements are set to 0. Then, We will count the incoming edges for a node and store it in this array. For example, if indegree of node 3 is 2, indegree[3] = 2.

Queue: As we will use BFS, a queue is required. Initially, the node with indegree 0 will be pushed into the queue.

Answer array: Initially empty and is used to store the linear ordering.
*/

/*
//Kahn's Algorithm
I)Calculate the indegree first of each node and store it in indegree array. 
We ca iterate through the given adj list and simply for every node u->v, 
we can increase the increase the indegree of v by 1 in the indegree array.
II)Initially there will be atleast a single node whose indegree is 0. So, we will push the node(s) with indegree 0 into  the queue.
III)Then, we will pop a node from the queue including the node in our answer array, 
and for all its adjacent nodes, 
we will decrease the indegree of that node by one.
For example, if node u that has been popped out from the queue has an edge towards node v(u->v), 
we will decrease indegree[v] by 1. 
IV)After that, if for any node the indegree becomes 0, we will push that node again into the queue.
V)We will repeat steps 3 and 4 until the queue is completely empty. Finally, completing the BFS we will get the linear ordering of the nodes in the answer array.
*/

#include<bits\stdc++.h>
using namespace std;
class Solution{
public:
  vector<int> topoSort(int V, vector<int> adj[]){
    int indegree[V]=0;
    for(int i=0; i<V; i++){
      for(auto it: adj[i]){
        indegree[it]++;
      }
    }
    queue<int> q;
    for(int i=0; i<V; i++){
      if(indegree[i]==0){
        q.push(i);
      }
    }

    vector<int> topo;
    while(!q.empty()){
      int node=q.front();
      q.pop();
      topo.push_back(node);

      for(auto it: adj[node]){
        indegree[it]--;
        if(indegree[it]==0) q.push(it);
      }
    }
    return topo;
  }
};
int main(){
  vector<int> adj[6]={{},{},{3},{1},{0,1},{0,2}};
  int V=6;
  Solution obj;
  vector<int> ans=obj.topoSort(V, adj);
  for(auto node: ans){
    cout<<node<<" ";
  }
  cout<<endl;
  return 0;
}