/**
 * @author Praveen Reddy Chalamalla
 * @create date 2022-05-18
 * @desc LeetCode 1192. Critical Connections in a Network
 */

//Time Complexity - O(V+E), Space Complexity - O(V)

#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>>criticalEdges ;
    vector<vector<int>>getAdjacencyList(vector<vector<int>>& g,int n){
        vector<vector<int>>adj(n);
        for(auto e:g){
            int u=e[0],v=e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        return adj;
    }
    void dfs(int u,vector<vector<int>>&adj, int &t, vector<int>&disc, vector<int>& low,vector<int>& parent ){
        disc[u]=low[u]=t;
        t++;
        for(auto v:adj[u]){
            if(disc[v]==-1){
                parent[v]=u;
                dfs(v,adj,t,disc,low,parent);
                low[u]=min(low[u],low[v]);
                //If the lowest discovery time of node that can be accessed from v is greater than the discovery time of u, 
                //there is no way to reach the sub graph in which u is present from the subgraph in which v  is present except through the edge between u,v
                if(disc[u]<low[v])criticalEdges.push_back(vector<int>({u,v})); 
            }
            else if(parent[u]!=v)low[u]=min(low[u],disc[v]); //Ignore child to parent edges
        }
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) { //Use Tarjan's Algo
       
        criticalEdges.clear();
        vector<vector<int>>adj=getAdjacencyList(connections,n); 
        
        vector<int>disc(n,-1),low(n,-1),parent(n,-1);
        int t=0;
        for(int i=0;i<n;i++){
            if(disc[i]==-1){
                dfs(i,adj,t,disc,low,parent);
            }
        }
        return criticalEdges;
    }
};