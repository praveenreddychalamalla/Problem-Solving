/**
 * @author Praveen Reddy Chalamalla
 * @create date 2022-05-31
 * @desc Leetcode : 91. Decode Ways
 */
#include <bits/stdc++.h>
using namespace std;
//Time Complexity - O(n) , Space Complexity - O(n)
class Solution {
	public:
    int p=1e9+7;
    int dp[10001];
    int count(string &s, int n){
        if(n==0)return 1;
        if(s[n-1]=='0')return 0;
        if(dp[n]!=-1)return dp[n];
        int d1=s[n-1]-'0'; //Invalid grouping, cannot start with '0'
        if(n>1){ //The digit at current position can be grouped alone or can be clubbed with next digit
            int d2=s[n-2]-'0';
            //Check if the current digit can be clubbed with next digit, if yes ==> then only we have two choices to explore
            if(d1*10+d2<27)return dp[n]=(count(s,n-1)+count(s,n-2))%p; 
        }
        return dp[n]=count(s,n-1); //Only option - Group this digit alone
    }
	int CountWays(string str){
	    memset(dp,-1,sizeof(dp));
	    reverse(str.begin(),str.end());
	    return count(str,str.length());
	}
};