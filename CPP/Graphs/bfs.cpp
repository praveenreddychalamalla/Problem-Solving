/**
 * @author Praveen Reddy Chalamalla
 * @create date 2021-06-21
 * @desc Given a connected undirected graph. Perform a BFS on the graph.
 */
#include<bits/stdc++.h>
using namespace std;

vector<int>bfsOfGraph(int V, vector<int> adj[])
{
    queue<int>q;
    vector<int>visited(V,0),v; 

    q.push(0); //Push the starting vertex into the queue and mark it as visited
    visited[0]=1;
    v.push_back(0);

    while(!q.empty()){
        int x=q.front();    //Current Node = x. Pop the node from queue
        q.pop();
        for(auto i:adj[x]){     //Explore the current node. All its neighbours are present in the adjacency list of vertex 'x' i.e., adj[x]
            
            if(!visited[i]){    //If you hit any vertex which is not visited, mark it as visited and push it into queue.
                visited[i]=1;
                v.push_back(i);
                q.push(i);
            }
        }
    }
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
        vector<int>ans=bfsOfGraph(V, adj);
        for(int i=0;i<ans.size();i++){
        	cout<<ans[i]<<" ";
        }
        cout<<endl;
	}
	return 0;
}  