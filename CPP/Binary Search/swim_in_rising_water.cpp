 /**
 * @author Praveen Reddy Chalamalla
 * @create date 2022-04-28
 * @desc 778. Swim in Rising Water : Binary Search with DFS
 */

//Time Complexity - O(n^2 log (max(elevation))) , Space Complexity - O(n^n)

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int m,n;
    bool visited[50][50];
    vector<vector<int>>dir={{1,0},{-1,0},{0,1},{0,-1}};
    bool dfs(vector<vector<int>>&a, int i, int j, int l){
        if(i<0||j<0||i>=m||j>=n||visited[i][j]||a[i][j]>l)return false;
        if(i==m-1 && j==n-1)return true;
        visited[i][j]=true;
        for(int k=0;k<4;k++){
            int x=i+dir[k][0],y=j+dir[k][1];
            if(dfs(a,x,y,l))return true;
        }
        return false;
        
    }
    int swimInWater(vector<vector<int>>& grid) {
        m=grid.size(),n=grid[0].size();
        int l=0,r=2500,res=0;
        while(l<=r){
            int m=(l+r)/2;
            memset(visited,0,sizeof(visited));
            if(dfs(grid,0,0,m)){ //Check if you can reach bottom right cell with time limit =m
                r=m-1;
                res=m;
            }
            else l=m+1;
        }
        return res;
    }
};