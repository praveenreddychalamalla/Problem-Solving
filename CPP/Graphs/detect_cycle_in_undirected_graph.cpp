 /**
 * @author Praveen Reddy Chalamalla
 * @create date 2021-12-26
 * @desc Given a UnDirected Graph with V vertices (Numbered from 0 to V-1) and E edges, check whether it contains any cycle or not.
 */

//Time Complexity - O(V+E), Space Complexity - O(V). Keeping track of recursion stack
#include<bits/stdc++.h>
using namespace std;

vector<bool>visited;
vector<bool>recStack;
bool checkCycle(int x, int p, vector<int> adj[]){
    if(!visited[x]){

        visited[x]=1; //Mark current vertex as visited.
        recStack[x]=1; //Insert current node into recursion stack

        for(auto i: adj[x]){ //Recurr for all the adjacent vertices of x
            if(i==p)continue;
            if(!visited[i]){ //If a vertex is not visited, then no way it could be present in recursion stack, hence call check cycle on this vertex
                if(checkCycle(i,x,adj)) return true;
            }
            else if(recStack[i]) return true; //If you hit a vertex which is already in recursion stack, it means that you are in same DFS (Un-backtracked) and hence in loop. 
        }
    }
    recStack[x]=0; //Pop the vertex out of recursion stack while backtracking as you did not find any cycle
    return false;
    
}

bool isCyclic(int V, vector<int> adj[]) {
    visited.resize(V,0);
    recStack.resize(V,0);
    for(int i=0;i<V;i++){
        if(!visited[i]){
            if(checkCycle(i,-1,adj))return true;
        }
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