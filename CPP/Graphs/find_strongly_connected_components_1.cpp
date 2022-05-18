/**
 * @author Praveen Reddy Chalamalla
 * @create date 2021-06-21
 * @desc Kosaraju's Algorithm - Given a Directed Graph with V vertices (Numbered from 0 to V-1) and E edges, Find the number of strongly connected components in the graph.
 */

/**
 * Single Node is always an SCC.
 * On reversing the edges in the Graph (Transpose of Graph), type of graph won't change i.e.. SCCs remain as SCCs 
 * 
 * Perform DFS on the graph initially and push the Nodes into stack while returning.
 * Reverse the edges of Graph
 * Perform DFS on the graph by popping a node from stack, if the node popped is not visited yet(Do this until stack is empty).
 * Performing DFS on any node of an SCC visits all other nodes in the same strongly connected component. 
 */

//Time Complexity - O(V+E), Space Complexity - O(V)
#include<bits/stdc++.h>
using namespace std;

unordered_map<int,vector<int>> rev;

void DFS1(int x,vector<int> adj[] ,vector<int>& visited, stack<int>& st){ //Modified DFS
    visited[x]=1;
    for(auto i:adj[x]){
        if(!visited[i])DFS1(i,adj,visited,st); //Recursive call 
    }
    st.push(x); //Push the nodes into stack while returning.
    
}
void reverse(int V,vector<int> adj[]){
    for(int i=0;i<V;i++){
        for(auto x:adj[i]){
            rev[x].push_back(i); //Reversing the edges. i-->j will be now j--->i
        }
    }
}
void DFS2(int x, vector<int>& visited){ //Regular DFS

    visited[x]=1;
    for(auto i: rev[x]){
        if(!visited[i])DFS2(i,visited);
    }
}
int kosaraju(int V, vector<int> adj[]){ //Kosaraju's algorithm can also be implemented with BFS also

    int cnt=0;
    stack<int>st;
    vector<int>visited(V,0);
    
    for(int i=0;i<V;i++){
        if(!visited[i])  DFS1(i,adj,visited,st); //Performing modified DFS on graph, so that all nodes are pushed into stack 
    }
    
    reverse(V,adj);
    for(int i=0;i<V;i++)visited[i]=0; //Mark all nodes as not visited

    while(!st.empty()){
        int x=st.top();
        st.pop();
        if(!visited[x]){ //If the popped node is not visited yet, it means that it belongs to some SCC, performing DFS on it makes to visit all the nodes in that SCC hence call DFS on that node.
            DFS2(x,visited); //All the nodes in the SCC to which X belongs to will be visited. Hence each DFS call accounts for 1 SCC
            cnt++;
        }
    }
    return cnt;
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

    	cout << kosaraju(V, adj) << "\n";
    }

    return 0;
}
