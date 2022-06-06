/**
 * @author Praveen Reddy Chalamalla
 * @create date 2022-06-06
 * @desc Minimum Spanning Tree
 */


#include<bits/stdc++.h>
using namespace std;
//Time Complexity - O(E log V), Space Complexity(v^2)
class Solution1
{
	public:
	
    int spanningTree(int V, vector<vector<int>> adj[]){
        int wt=0,n=V;
        vector<bool>inMST(V,0);
        vector<int>key(V,INT_MAX);
        //Use a parent array to get the edges of MST
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        pq.push({0,0});
        while(!pq.empty()){
            int u=pq.top().second,cost=pq.top().first;
            pq.pop();
            if(inMST[u])continue;
            inMST[u]=true;
            wt+=cost;
            for(auto e:adj[u]){
                int v=e[0],w=e[1];
                if(!inMST[v] && key[v]>w){ //Decrease the key of vertices which are not yet added to MST
                    key[v]=w;
                    pq.push({w,v});
                }
            }
        }
        return wt;
    }
};

//Time Complexity - O(v^2), Space Complexity - O(v)
class Solution2
{
    //To implement the same algorithm with a binary heap, you need to support the heap with decrease key operation which is not provided in STL pq container. Hence tweak the algo little bit
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
	void updateKeys(int u , vector<int>&key, vector<vector<int>>& list){
	    for(auto e:list){
	        int v=e[0],w=e[1];
	        key[v]=min(key[v],w); 
	    }
	}
	int extractMin(vector<int>& key,vector<int>&visited, int n){
	    int j=-1,d=INT_MAX;
	    for(int i=0;i<n;i++){
	        if(!visited[i] && key[i]<d){ 
	            d=key[i];
	            j=i;
	        }
	    }
	    return j;
	}
    int spanningTree(int V, vector<vector<int>> adj[]){
        int wt=0,n=V;
        //visited array is used to keep track of InMst vertices
        vector<int>visited(V,0),key(V,INT_MAX); //Key[i] holds the weight of the edge that can used to connect vertex i to exisiting MST SET 
        //Use a parent array to get the edges of MST
        key[0]=0;
        while(n){
            int u=extractMin(key,visited,V);
            visited[u]=1;
            wt+=key[u];
            updateKeys(u,key,adj[u]); //Decrease key 
            n--;
        }
        priority_queue<array<int,2>,vector<array<int,2>>,greater<array<int,2>>()>pq;
        return wt;
    }
};