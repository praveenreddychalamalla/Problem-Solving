 /**
 * @author Praveen Reddy Chalamalla
 * @create date 2022-05-14
 * @desc Leetcode: 743. Network Delay Time
 */

//Time Complexity - O(n log n), Space Complexity - O(n).
#include<bits/stdc++.h>
using namespace std;
class Compare{
    public:
        bool operator()(pair<int,int>&a, pair<int,int>&b){return a.second>b.second;}
};
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<int>visited(n+1,INT_MAX);
        unordered_map<int,vector<pair<int,int>>>adj;
        for(int i=0;i<times.size();i++)adj[times[i][0]].push_back({times[i][1],times[i][2]});
        priority_queue<pair<int,int>,vector<pair<int,int>>,Compare>pq;
        visited[k]=0;
        pq.push({k,0});
        while(!pq.empty()){
            auto p=pq.top();
            int u=p.first,t1=p.second;
            pq.pop();
            for(auto e:adj[u]){ //Try to relax all outgoing edges of u
                int v=e.first,t2=e.second;
                if(visited[v]>t1+t2){ 
                    visited[v]=t1+t2; 
                    pq.push({v,t1+t2});
                }
            }
        }
        
        int ans=*max_element(visited.begin()+1,visited.end());
        return ans==INT_MAX?-1:ans;
    }
};