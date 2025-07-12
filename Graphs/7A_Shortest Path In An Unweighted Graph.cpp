#include<queue>
#include<vector>
vector<int> shortestPath( vector<pair<int,int>> edges , int n , int m, int s , int t){
	
	// Create Adjacency list
	vector<vector<int>> adj(n+1);
	for(int i=0; i<edges.size(); i++){
		int u=edges[i].first;
		int v=edges[i].second;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

    //do bfs
	vector<bool> visited(n+1,0);
	vector<int> parent(n+1,-1);
	queue<int> q;

	q.push(s);
	visited[s]=1;
	while(!q.empty()){
		int front=q.front();
		q.pop();
		for(auto i: adj[front]){
			if(!visited[i]){
				visited[i]=1;
				parent[i]=front;
				q.push(i);
			}
		}
	}

	//Create shortest Path
	vector<int> ans;
	int current_node=t;
	ans.push_back(t);

	while(current_node!=s){
		current_node=parent[current_node];
		ans.push_back(current_node);
	}

    reverse(ans.begin(), ans.end());
	return ans;	 
}
