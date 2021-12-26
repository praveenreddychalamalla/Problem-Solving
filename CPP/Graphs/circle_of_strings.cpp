#include<bits/stdc++.h>
using namespace std;
class Solution
{
    public:
    vector<bool>visited;
    void dfs(int u, vector<vector<int>>&adj){
        if(visited[u])return ;
        visited[u]=true;
        for(auto x:adj[u])dfs(x,adj);
    }
    int isCircle(int N, vector<string> A){
       vector<int>in(26,0),out(26,0);
       vector<vector<int>>adj(26);
       for(int i=0;i<N;i++){
           in[A[i].back()-'a']++;
           out[A[i].front()-'a']++;
           adj[A[i].front()-'a'].push_back(A[i].back()-'a');//Add edge from first character to last character of every string 
       }
       for(int i=0;i<26;i++){
           if(in[i]!=out[i])return 0;//Eulerian path can only be found if all the vertices same indegree and out degree
       }
       visited.resize(26,0);
       for(int i=0;i<26;i++){
           if(out[i]){
               dfs(i,adj);
               break;
           }
       }
       for(int i=0;i<26;i++)if(out[i] && !visited[i])return 0;
       return 1;
    }
};