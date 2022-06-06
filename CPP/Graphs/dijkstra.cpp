/**
 * @author Praveen Reddy Chalamalla
 * @create date 2022-06-06
 * @desc Dijkstra's Algorithm
 */
#include<bits/stdc++.h>
using namespace std;
//Time Complexity - O(E log V), Space Complexity - O(v)
class Solution1{
    
	public:
	
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S){

        int n=V;
        vector<int>dist(V,INT_MAX);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        pq.push({0,S});
        dist[S]=0;
        while(!pq.empty()){
            int u=pq.top().second,w=pq.top().first;
            pq.pop();
            for(auto e:adj[u]){ //Relax Every Outgoing edge from u
                int v=e[0],w=e[1];
                if(dist[v]>dist[u]+w){
                    pq.push({w,v});
                    dist[v]=dist[u]+w;
                }
            }
        }
        return dist;
    }
};

//Time Complexity - O(v^2), Space Complexity- O(v)
class Solution2
{
	public:
    int extractMin(vector<int>&dist,vector<bool>&visited,int n){
        int j=-1,d=INT_MAX;
        for(int i=0;i<n;i++){
            if(!visited[i]&& dist[i]<d){
                d=dist[i];
                j=i;
            }
        }
        return j;
    }
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S){
        vector<int>dist(V,INT_MAX);
        vector<bool>visited(V,false);
        dist[S]=0;
        int n=V;
        while(n){
            int u=extractMin(dist,visited,V);
            visited[u]=true;
            for(auto e:adj[u]){
                int v=e[0],w=e[1];
                dist[v]=min(dist[v],dist[u]+w);
            }
            n--;
        }
        return dist;
    }
};
