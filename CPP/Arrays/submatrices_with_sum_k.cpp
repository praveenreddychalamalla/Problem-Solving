/**
 * @author Praveen Reddy Chalamalla
 * @create date 2022-07-18
 * @desc Sub Matrices with target sum.
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {//Time Complexity - O(m*n*n), Space Complexity - O(m*n)
public:
    int numSubmatrixSumTarget(vector<vector<int>>& a, int target) {
        int m=a.size(),n=a[0].size(),res=0;
        vector<vector<int>>prefix(m,vector<int>(n,0));
        unordered_map<int,int>um;
        for(int i=0;i<m;i++){   //Prefix sum for each row
            prefix[i][0]=a[i][0];
            for(int j=1;j<n;j++){
                prefix[i][j]=prefix[i][j-1]+a[i][j]; 
            }
        }
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                int sum=0;
                um.clear();
                um[0]=1;
                for(int k=0;k<m;k++){
                    sum+=prefix[k][j]- (i>0? prefix[k][i-1]:0); //Accumulating the sum of rows between columns [i,j]. Similar to sub array with sum k logic
                    if(um.find(sum-target)!=um.end())res+=um[sum-target];
                    um[sum]++;
                }
            }
        }
        return res;
    }
};