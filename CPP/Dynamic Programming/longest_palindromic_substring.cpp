/**
 * @author Praveen Reddy Chalamalla
 * @create date 2022-05-30
 * @desc Given a string, find the length of the longest palindromic substring.
 */
#include<bits/stdc++.h>
using namespace std;

//Time Complexity - O(n^2), Space Complexity - O(n^2)
class Solution {
public:
    int dp[1000][1000];
    int LPS(string &s, int i, int j){
        if(i>j)return 0;
        if(i==j)return 1;
        if(dp[i][j]!=-1)return dp[i][j];
        if(s[i]==s[j]){ //Characters at i and j are same
            int remlps=LPS(s,i+1,j-1);
            if(remlps==j-i-1){ //If the substring between i and j is also a palindrome, it can be extended by adding these two characters
                return dp[i][j]=2+remlps;
            }
        }
        return dp[i][j]=max(LPS(s,i+1,j),LPS(s,i,j-1));
    }
    int longestPalindrome(string s) {
        memset(dp,-1,sizeof(dp));
        return LPS(s,0,s.length()-1);
    }
};
/**
 * Recursive Solution - Time Complexity =O(2^n), Space Complexity - O(n)
 * int LPS(string &s, int i, int j){
        if(i>j)return 0;
        if(i==j)return 1;

        if(s[i]==s[j]){ //Characters at i and j are same

            int remlps=LPS(s,i+1,j-1);

            if(remlps==j-i-1){ //If the substring between i and j is also a palindrome, it can be extended by adding these two characters
                return 2+remlps;
            }
        }
        return max(LPS(s,i+1,j),LPS(s,i,j-1));
    }
 * 
 *  Tabulation - Bottom Up :
 * 
 *  int LPS(string s) {
        int cnt=0,n=s.length(),lmax=1;

        vector<vector<int>>dp(n,vector<int>(n,false));

        for(int i=0;i<n;i++)dp[i][i]=true,cnt++; //1 length palindromes

        for(int i=0;i<n-1;i++){ //2 length palindromes
            if(s[i]==s[i+1])dp[i][i+1]=true,cnt++;
            else dp[i][i+1]=false;
            if(dp[i][j])lmax=2;
        }
        
        for(int k=2;k<n;k++){ //K+1 length palindromes

            for(int i=0;i<n-k;i++){

                int j=i+k;
                if(s[i]==s[j] && dp[i+1][j-1])dp[i][j]=true,cnt++; //If substring between i and j is palindrome and s[i]==s[j]
                else dp[i][j]=false;

                if(dp[i][j])lmax=max(lmax,j-i+1); //update lmax
            }
        }
        return cnt;
    }
 * 
 */