/**
 * @author Praveen Reddy Chalamalla
 * @create date 2022-07-13
 * @desc Leetcode : https://leetcode.com/problems/partition-to-k-equal-sum-subsets/
 * 
 */
#include<bits/stdc++.h>
using namespace std;

//Time Complexity - (k^n), Space Complexity - O(n). Number in hand and placing the number in one of the K buckets (subsets)
class Solution1 { 
public:
    bool solve(vector<int>&a, int n, vector<int>&s, int k, int limit){
        if(n==0){
            for(int i=0;i<k;i++){
                if(s[i]!=limit)return false;
            }
            return true;
        }
        for(int i=0;i<k;i++){
            if(s[i]+a[n-1]<=limit){
                s[i]+=a[n-1];
                if(solve(a,n-1,s,k,limit))return true;
                s[i]-=a[n-1];
            }
        }
        return false;
    }
    
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int limit=accumulate(nums.begin(),nums.end(),0);
        if(limit%k)return false;
        limit/=k;
        vector<int>s(k,0);
        return solve(nums,nums.size(),s,k,limit);
    }
};

//Time Complexity - (2^(n*k)), Space Complexity - O(n). Bucket in hand and picking from the available numbers into the bucket.
//This can be memoized. Maintain a visited array in a mask. A mask indicates the state of unchoosed elements. Can you produce k equal subsets from this state? (From unchoosen elements)
class Solution {
public:
    bool visited[16];
    int limit,n;
    bool solve(vector<int>&a, int sum, int k){
        if(sum==limit)return solve(a,0,k-1);
        if(k==1)return true;
        for(int j=0;j<n;j++){
            if(!visited[j] && sum+a[j]<=limit){
                visited[j]=true;
                if(solve(a,sum+a[j],k))return true;
                visited[j]=false;
            }
        }
        return false;
    }
    
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        memset(visited,0,sizeof(visited));
        n=nums.size();
        limit=accumulate(nums.begin(),nums.end(),0);
        if(limit%k)return false;
        limit/=k;
        return solve(nums,0,k);
    }
};

//Time Complexity - (k*(2^n)), Space Complexity - O(k*(2^n)).
class Solution3 {
public:
    int dp[1<<16][16];
    int limit,n;
    bool solve(vector<int>&a, int sum, int mask, int k){
        if(k==1)return true;
        if(dp[mask][k]!=-1)return dp[mask][k];
        if(sum==limit)return dp[mask][k]=solve(a,0,mask,k-1);
        for(int j=0;j<n;j++){
            if(sum+a[j]<=limit && !(mask&(1<<j))){
                if(solve(a,sum+a[j],mask|(1<<j),k))return dp[mask][k]=true;
            }
        }
        return dp[mask][k]=false;
    }
    
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        memset(dp,-1,sizeof(dp));
        n=nums.size();
        limit=accumulate(nums.begin(),nums.end(),0);
        if(limit%k)return false;
        limit/=k;
        return solve(nums,0,0,k);
    }
};