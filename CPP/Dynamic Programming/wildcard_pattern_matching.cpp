/**
 * @author Praveen Reddy Chalamalla
 * @create date 2022-05-31
 * @desc Wildcard Pattern Matching
 */

#include <bits/stdc++.h>
using namespace std;
class Solution{
  public:
    int dp[201][201];

    bool match(string& x, string& y, int m, int n){
        
        if(m==0 && n==0)return true; //Match found
        
        if(m==0)return false; //Pattern completed, but still string is remaining, hence invalid
        
        if(n==0){ //String completed, but pattern is still remaining. Check if the remaining pattern can be used to derive empty string
           
            //Check if all the remaining characters in the pattern are stars ('*')
            while(m){
                if(x[m-1]=='*')m--;
                else break;
            }
            return m==0;
        }
        if(dp[m][n]!=-1)return dp[m][n];

        if(x[m-1]=='?'){ //No option ==> Character at y[n-1] must be matched with '?' at x[m-1]
            return dp[m][n]=match(x,y,m-1,n-1);
        }

        else if(x[m-1]=='*'){ //Character at y[n-1] can be matched with '*' at x[m-1] or '*' at x[m-1] can be ignored
            return dp[m][n]=(match(x,y,m-1,n)||match(x,y,m,n-1));//Don't reduce pattern size when character at y[n-1] is matched with '*', because '*' can eatup more characters
        }
        
        else { //No option ==> Characters at y[n-1], x[m-1] must be same
            if(x[m-1]==y[n-1])return dp[m][n]=match(x,y,m-1,n-1); 
            else return dp[m][n]=false;
        }
    }
    int wildCard(string pattern,string str){
        memset(dp,-1,sizeof(dp));
        int m=pattern.length(),n=str.length();
        return match(pattern,str,m,n)?1:0;
    }
};