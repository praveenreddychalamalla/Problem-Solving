/**
 * @author Praveen Reddy Chalamalla
 * @create date 2022-06-06
 * @desc Bellman Ford Algorithm
 */
#include<bits/stdc++.h>
using namespace std;
//Time Complexity - O(E * V), Space Complexity - O(1)
class Solution{
	public:
    vector <int> bellman_ford(int V, vector<vector<int>> adj, int S) {
        vector<int>dist(V,INT_MAX);
        dist[S]=0;
        /**
         * Dijkstra Vs Bellman Ford : 
         * In dijsktra we will relax only outgoing edges of the picked vertex (Extract Min), but in bellman ford we will relax all the edges.
         * Every edge is relaxed V-1 times.
         */
        for(int i=0;i<V-1;i++){ //We relax edges of path length 'i'. The shortest path b/w Source and Dest may include V-1 vertices in worst case
            for(auto e:adj){
                int u=e[0],v=e[1],w=e[2];
                if(dist[u]!=INT_MAX && dist[v]>dist[u]+w){
                    dist[v]=dist[u]+w;
                }
            }
        }
        //To detect -ve edge weight cycles, try to relax all the edges once more. If there is any decrease in distance, it indicates the -ve edge weight cycles
        return dist;
    }
};