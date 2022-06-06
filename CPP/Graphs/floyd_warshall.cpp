/**
 * @author Praveen Reddy Chalamalla
 * @create date 2022-06-06
 * @desc Floyd Warshall's Algorithm
 */
#include<bits/stdc++.h>
using namespace std;
//Time Complexity - O(n^3), Space Complexity - O(1)
class Solution {
  public:
	void shortest_distance(vector<vector<int>>&dp){
	    int V=dp.size();
	    for(int k=0;k<V;k++){ //Pick every vertex and check if it is an intermediate vertex in the shortest path between i and j and update
	        for(int i=0;i<V;i++){
	            for(int j=0;j<V;j++){
	                if(dp[i][k]!=-1 && dp[k][j]!=-1){
	                   if(dp[i][j]==-1)dp[i][j]=dp[i][k]+dp[k][j];
	                   else dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]);
	                }
	            }
	        }
	    }
	}
};