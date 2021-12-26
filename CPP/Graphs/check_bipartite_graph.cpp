 /**
 * @author Praveen Reddy Chalamalla
 * @create date 2021-12-26
 * @desc Given an adjacency list of a graph adj  of V no. of vertices having 0 based index. Check whether the graph is bipartite or not.
 */

//Time Complexity - O(V+E), Space Complexity - O(V)
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<bool>visited;
    vector<int>color;
    bool dfs(int u,int p, vector<int>adj[]){ //similar to cycle detection
        if(!visited[u]){
            visited[u]=true;
            if(p==-1)color[u]=0; //If parent==-1, you can use any color, to color the node
            else color[u]=!color[p]; //color the node with the color opposite to the parent node color
            int m=adj[u].size();
            for(int i=0;i<m;i++){
                int v=adj[u][i];
                if(dfs(v,u,adj))return true; 
            }
            return false;
        }
        else{
            return color[u]==color[p]; //if the node is already visited, check if the node and its parent (adjacent) have same color
        }
    }
	bool isBipartite(int V, vector<int>adj[]){
	    queue<int>q;
	    color.resize(V,-1);
	    visited.resize(V,0);
	    for(int i=0;i<V;i++){ //DFS Traversal
	        if(!visited[i]){
	            if(dfs(i,-1,adj)) return false;
	        }
	    }
	    return true;
	}

};