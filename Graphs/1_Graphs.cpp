//M1

#include<iostream>
#include<unordered_map>
#include<queue>
#include<set>
#include<list>

using namespace std;



void prepareAdjList(unordered_map<int, list<int> > &adjList, vector<pair<int, int>> &edges){
  for(int i=0; i<edges.size(); i++){
    int u=edges[i].first;
    int v=edges[i].second;

    adjList[u].push_back(v);
    adjList[v].push_back(u);
  }
}

void bfs(unordered_map<int, list<int> > &adjList, unordered_map<int, bool> visited, vector<int> &ans, int node){
  queue<int> q;
  q.push(node);
  visited[node]==1;

  while(!q.empty()){
    int frontNode=q.front();
    q.pop();
  }

  //store frontNode into ans
  ans.push_back(frontNode);

  //traverse all neighbours of frontNode
  for(auto i:adjList{frontNode}){
    if(!visited[i]){
      q.push(i);
      visited[i]=1;
    }
  }
}
vector<int> BFS(int vertex, vector<pair<int, int>> edges){
  unordered_map<int, list<int>> adjList;
  vector<int> ans;
  unordered_map<int, bool> visited;
  prepareAdjList(adjList,edges);
  
  //traverse all the components of a graph
  for(int i=0;  i<vertex; i++){
    if(visited[i]){
      bfs(adjList,visited,ans ,i);
    }
  }
}


//M2

#include <bits/stdc++.h>
using namespace std;
template <typename T>
class graph
{
public:
  // unordered_map<int, list<int>> adj; // int is the index that stores the value and list<int> stores the nodes connected to that particular node(index)
  unordered_map<T, list<T>> adj;
  // void addEdge(int u, int v, bool direction)
  void addEdge(T u, T v, bool direction)
  {
    // direction=0 -> undirected
    // direction=1 -> directed

    // create an edge from u to v
    adj[u].push_back(v);
    if (direction == 0)
    {
      adj[v].push_back(u);
    }
  }

  // to print the adjacency list formed
  void printAdjList()
  {
    for (auto it : adj)
    {
      cout << it.first << "->";
      for (auto j : it.second)
      {
        cout << j << ", ";
      }
      cout << endl;
    }
  }
};

int main()
{
  int n;
  cout << "Enter the number of nodes " << endl;
  cin >> n;
  int m;
  cout << "enter the number of edges " << endl;
  cin >> m;

  graph<int> g; // becue we used template <typename T>, this graph can be anything: <int>, <char> etc.
  for (int i = 0; i < m; i++)
  {
    int u, v;
    cin >> u >> v;
    // creating an undirected graph
    g.addEdge(u, v, 0);
  }

  // printing the graph
  g.printAdjList();

  return 0;
}
