#include<bits/stdc++.h>
using namespace std;

class Graph{}{
  public:
    vector<int, vector<pair<int,int>>> adj;
    void addEdge(int u, int v , int weight){
      pair<int, int> p=make_pair(v, weight);
      adj[u].push_back(p);
    }
};