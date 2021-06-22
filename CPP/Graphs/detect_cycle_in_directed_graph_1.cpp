/**
 * @author Praveen Reddy Chalamalla
 * @create date 2021-06-22
 * @desc Given a Directed Graph with V vertices (Numbered from 0 to V-1) and E edges, check whether it contains any cycle or not.
 */

//Time Complexity - O(V*E), Space Complexity - O(V). Keeping track of recursion stack will bring down the Time Complexity to O(V+E).
#include<bits/stdc++.h>
using namespace std;

bool checkCycle(vector<int>& visited, vector<int> adj[],int x){     //DFS
    if(visited[x]) return true; //Visiting an already visited vertex indicates that we are in a loop (Cycle)
    
    visited[x]=1;
    for(auto i:adj[x]){
        if(checkCycle(visited,adj,i)) return true;
    }
    visited[x]=0; //Mark current vertex as not visited while backtracking as you did not find any cycle
    
    return false;
    
}
bool isCyclic(int V, vector<int> adj[]) 
{
    vector<int>visited(V,0); //Mark all nodes as not visited

    for(int i=0;i<V;i++){ //Process each vertex. O(V)

        visited[i]=1;
        for(auto j:adj[i]){ //Process adjacency list of each Vertex . In worst case, for every vertex i, you might visit all the edges of the graph and end up not finding a cycle 
            if(checkCycle(visited,adj,j)) return true; //Check if there exists a cycle starting with vertex i. Perform DFS 
        }
        visited[i]=0;
    }
    return false;
}

int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E;
    	cin >> V >> E;

    	vector<int> adj[V];

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
        }

    	cout << isCyclic(V, adj) << "\n";
    }

    return 0;
}