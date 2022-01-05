/**
 * @author Praveen Reddy Chalamalla
 * @create date 2022-01-05
 * @desc Target Sum Problem 
 */

//Time Complexity - O(n*sum_of numbers), Space Complexity - O(n*sum_of numbers)

#include<bits/stdc++.h>
using namespace std;
/**
 * Recursive Solution
 * class Solution {
    public:
        int CTSW(int n, int s, vector<int>&a, int sum){
            if(n==0)return s==sum;
            return CTSW(n-1,s+a[n-1],a,sum)+CTSW(n-1,s-a[n-1],a,sum);
        }
        int findTargetSumWays(vector<int>& nums, int target) {
            int n=nums.size();
            return CTSW(n,0,nums,target);
        }
    };
 * For Memoisation - dp[n][s+1] will not work, s can be negative in this case. Hence Scale the range from [-Sum ,+Sum] to [0,2*Sum+1]
 *                   -Sum ~ 0 ==> add a bias of Sum to every sum obtained while storing in DP table
 *                   Hence Column j corresponds to j- Sum originally 
 */
class Solution {
public:
    vector<vector<int>>dp;
    int CTSW(int n, int s, vector<int>&a, int sum, int bias){ //CTSW count target sum ways
        if(n==0)return s==sum; // 0/1
        if(dp[n][s+bias]!=-1)return dp[n][s+bias];
        return dp[n][s+bias]=CTSW(n-1,s+a[n-1],a,sum,bias)+CTSW(n-1,s-a[n-1],a,sum,bias);
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size();
        int s=0;
        for(int i=0;i<n;i++)s+=nums[i];
        dp.resize(n+1,vector<int>(2*s+1));
        fill(dp.begin(),dp.end(),vector<int>(2*s+1,-1));
        return CTSW(n,0,nums,target,s);
    }
};