/**
 * @author Praveen Reddy Chalamalla
 * @create date 2021-06-21
 * @desc Given a connected undirected graph. Perform a DFS on the graph.
 */
#include<bits/stdc++.h>
using namespace std;

vector<int>visited;
vector<int>v;
void DFS(int x, vector<int> adj[]){
    visited[x]=1;
    v.push_back(x);
    for(auto i:adj[x]){
        if(!visited[i]) DFS(i,adj);
    }
}
vector<int>dfsOfGraph(int V, vector<int> adj[])
{
    for(int i=0;i<V;i++)visited.push_back(0);
    DFS(0,adj);
    return v;
}

int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
    	cin >> V >> E;

    	vector<int> adj[V];

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    		adj[v].push_back(u);
        }
        vector<int>ans=dfsOfGraph(V, adj);
        for(int i=0;i<ans.size();i++){
        	cout<<ans[i]<<" ";
        }
        cout<<endl;
	}
	return 0;
}  