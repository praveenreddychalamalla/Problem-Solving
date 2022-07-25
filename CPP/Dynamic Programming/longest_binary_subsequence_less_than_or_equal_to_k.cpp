/**
 * @author Praveen Reddy Chalamalla
 * @create date 2022-07-06
 * @desc 2311. Longest Binary Subsequence Less Than or Equal to K. K<=1e9
 */
#include<bits/stdc++.h>
using namespace std;
/**
 * 1<<32 ==> integer overflow error. 
 * Though k is a changing variable between recursive function calls, you don't need a variable (state) to maintain in dp!!
 * k is not an independent variable here. At every stage, you are just saving the value left which is computed using l and s[i].
 * Hence effective state variables are i and l. i<=1000 and l<=1000. 
 */
class Solution { //Time , Space - O(n^2)
public:
    int dp[1001][1001];
    int solve(string& s, int i, int l, long long k){
        if(i<0)return 0;
        if(dp[i][l]!=-1)return dp[i][l];
        long long val=(((long long)s[i]-'0')<<min(32,l)); //If previous subsequence len==32, Putting a 1 even before 32 0's will exceed the val of k.
        if(val<=k) return dp[i][l]=max(1+solve(s,i-1,l+1,k-val),solve(s,i-1,l,k));
        else return dp[i][l]=solve(s,i-1,l,k);
    }
    int longestSubsequence(string s, int k) {
        memset(dp,-1,sizeof(dp));
        return solve(s,s.length()-1,0,k);
    }
};