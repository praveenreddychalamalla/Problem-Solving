/**
 * @author Praveen Reddy Chalamalla
 * @create date 2022-05-18
 * @desc Tarjan's Algorithm - Given a Directed Graph with V vertices (Numbered from 0 to V-1) and E edges, Find the members of strongly connected components in the graph.
 */

//Time Complexity - O(V+E), Space Complexity - O(V)
#include<bits/stdc++.h>
using namespace std;

class Solution
{
	public:
    vector<vector<int>>res;
    void dfs(int u, vector<int> adj[],int &t, vector<int>&disc, vector<int>& low, vector<bool>&recStack,stack<int>&st){
        disc[u]=low[u]=t; //Assign discovery time , lowest discovery time of node that can be accessed from this node to t;
        t++;
        st.push(u); 
        recStack[u]=true; //Keep track of the nodes that are present in stack. Will be used to differentiate between a back edge and cross edge
        for(auto v:adj[u]){
            if(disc[v]==-1){//Not visited yet.
                dfs(v,adj,t,disc,low,recStack,st);
                low[u]=min(low[u],low[v]); //Update the lowest discovery time  of node that can be accessed from this node from the future node, if there is any fall
            }
            else if(recStack[v]){ //Indicates that the edge between u and v is a back edge. Hence update the low. If it is a cross edge, ignore it (v is not present in recStack)
                low[u]=min(low[u],disc[v]);
            }
        }
        if(disc[u]==low[u]){ //Indicates the head of SCC. Pull out all the nodes of this SCC from stack
            vector<int>scc;
            while(st.top()!=u){
                int v=st.top();
                st.pop();
                recStack[v]=false;
                scc.push_back(v);
            }
            recStack[st.top()]=false;
            scc.push_back(st.top());
            st.pop();
            
            sort(scc.begin(),scc.end());
            res.push_back(scc);
        }
    }
    vector<vector<int>> tarjans(int V, vector<int> adj[]){
        res.clear();
        vector<int>disc(V,-1),low(V,-1);
        vector<bool>recStack(V,false);
        stack<int>st;
        int t=0;
        for(int u=0;u<V;u++){
            if(disc[u]==-1)dfs(u,adj,t,disc,low,recStack,st);
        }
        sort(res.begin(),res.end());
        return res;
    }
};
