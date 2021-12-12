/**
 * @author Praveen Reddy Chalamalla
 * @create date 2021-12-21
 * @desc Given a Directed Acyclic Graph (DAG) with V vertices and E edges, Find any Topological Sorting of that Graph.
 */

//Time Complexity - O(V+E), Space Complexity - O(V)
#include<bits/stdc++.h>
using namespace std;

vector<bool>visited;
void dfs(int u,vector<int> adj[], stack<int>&st){
    if(!visited[u]){
        visited[u]=true;
        for(auto x:adj[u])dfs(x,adj,st);
        st.push(u); //Store the node whenever dfs on a node is finished. All the neighbours will be pushed into stack already (preserves the toposort order)
    }
}
vector<int> topoSort(int V, vector<int> adj[]) {
    visited.resize(V,false);
    stack<int>st;
    for(int i=0;i<V;i++){ //Apply dfs on the graph
        if(!visited[i])dfs(i,adj,st);
    }
    vector<int>res;
    while(!st.empty())res.push_back(st.top()),st.pop();
    return res;
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
        vector<int>ans=topoSort(V, adj);
        for(int i=0;i<ans.size();i++){
        	cout<<ans[i]<<" ";
        }
        cout<<endl;
	}
	return 0;
}  