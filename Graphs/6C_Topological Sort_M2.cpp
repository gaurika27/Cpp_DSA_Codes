//Strivers
/*
Topological sorting only exists in Directed Acyclic Graph (DAG). If the nodes of a graph are connected through directed edges and the graph does not contain a cycle, it is called a directed acyclic graph(DAG). 

The topological sorting of a directed acyclic graph is nothing but the linear ordering of vertices such that if there is an edge between node u and v(u -> v), node u appears before v in that ordering.

Now, let's understand Why topological sort only exists in DAG:

Case 1 (If the edges are undirected): If there is an undirected edge between node u and v, it signifies that there is an edge from node u to v(u -> v) as well as there is an edge from node v to u(v -> u). But according to the definition of topological sorting, it is practically impossible to write such ordering where u appears before v and v appears before u simultaneously. So, it is only possible for directed edges.
Case 2(If the directed graph contains a cycle): The following directed graph contains a cycle:

If we try to get topological sorting of this cyclic graph, for edge 1->2, node 1 must appear before 2, for edge 2->3, node 2 must appear before 3, and for edge 3->1, node 3 must appear before 1 in the linear ordering. But such ordering is not possible as there exists a cyclic dependency in the graph. Thereby, topological sorting is only possible for a directed acyclic graph.
*/
/*
//Algorithm

I)Traverse all components of the graph
II)Make a visited array and initialize all elements to 0. 
III)Make a stack data structure to store the nodes after completing the dfs call.
IV)In the dfs call, first, the current node is marked as visited. Then dfs call is made for all its adjacent nodes.
V)After visiting all its adjacent nodes, DFS will backtrack to the previous node and meanwhile, the current node is pushed into the stack.
VI)Finally, we will get the stack containing one of the topological sortings of the graph.
*/
#include<bits\stdc++.h>
using namespace std;
class Solution(
private:
  void dfs(int node, int vis[], stack<int> st, vector<int> adj[]){
    vis[node]=1;
    for(auto it: adj[node]){
      if(!vis[it]) dfs(it, vis, st, adj);
    }
    st.push(node);
  }
public:
  vector<int> topoSort(int V, vector<int> adj[]){
    int vis[V]={0};
    stack<int> st;
    for(int i=0; i<V; i++){
      if(!vis[i]){
        dfs(i, vis, st, adj);
      }
    }

    vector<int> ans;
    while(!st.empty()){
      ans.push_back(st.top());
      st.pop();
    }
    return ans;
  }
);
int main(){
  vector<int> adj[6]={{},{},{3},{1},{0,1},{0,2}};
  int V=6;
  Solution obj;
  vector<int> ans=obj,].topoSort(V, adj);
  for(auto node: ans){
    cout<<node<<" ";
  }
  cout<<endl;

  return 0;
}
