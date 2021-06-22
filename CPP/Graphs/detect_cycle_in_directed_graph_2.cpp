/**
 * @author Praveen Reddy Chalamalla
 * @create date 2021-06-22
 * @desc Given a Directed Graph with V vertices (Numbered from 0 to V-1) and E edges, check whether it contains any cycle or not.
 */

//Time Complexity - O(V+E), Space Complexity - O(V). Keeping track of recursion stack
#include<bits/stdc++.h>
using namespace std;

bool checkCycle(vector<int>& recStack,vector<int>& visited, vector<int> adj[],int x){
    if(!visited[x]){

        visited[x]=1; //Mark current vertex as visited.
        recStack[x]=1; //Insert current node into recursion stack

        for(auto i: adj[x]){ //Recurr for all the adjacent vertices of x

            if(!visited[i]){ //If a vertex is not visited, then no way it could be present in recursion stack, hence call check cycle on this vertex
                if(checkCycle(recStack,visited,adj,i)) return true;
            }
            else if(recStack[i]) return true; //If you hit a vertex which is already in recursion stack, it means that you are in same DFS (Un-backtracked) and hence in loop. 
        }
    }
    recStack[x]=0; //Pop the vertex out of recursion stack while backtracking as you did not find any cycle
    return false;
    
}

bool isCyclic(int V, vector<int> adj[]) 
{
    vector<int>visited(V,0),recStack(V,0); // recStack helps to know whether a vertex is in the current recursion stack or not
    for(int i=0;i<V;i++){
        if(checkCycle(recStack,visited,adj,i)) return true; //Modified DFS
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