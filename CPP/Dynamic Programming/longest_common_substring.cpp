/**
 * @author Praveen Reddy Chalamalla
 * @create date 2021-06-27
 * @desc Given two strings. The task is to find the length of the longest common substring.
 */
#include<bits/stdc++.h>
using namespace std;

int cur=0,res=0;
int longestCommonSubString (string s1, string s2, int n, int m){
    vector<vector<int>>dp;
    int res=0;
    for(int i=0;i<=n;i++) dp.push_back(vector<int>(m+1));
    for(int i=0;i<=n;i++)dp[i][0]=0; //Fill First row with Zeroes for simplicity
    for(int i=0;i<=m;i++)dp[0][i]=0; //Fill First Col with Zeroes for simplicity
    for(int i=1;i<=n;i++){ 
        for(int j=1;j<=m;j++){
            if(s1[i-1]==s2[j-1]){  //If characters match
                dp[i][j]=1+dp[i-1][j-1];
                res=max(res,dp[i][j]); //Update res.
            }
            else dp[i][j]=0;
        }
    }
    return res;
}
/**
 * Recursive Approach - Time Complexity: Exponential
    int cur=0,res=0;
    void lcs(string s1,string s2, int i,int j,int n,int m,bool flag){
        if(i<n&&j<m){
            if(flag&&s1[i]==s2[j]){
                cur++;
                res=max(res,cur);
                lcs(s1,s2,i+1,j+1,n,m,true);
            }
            else if(!flag && s1[i]==s2[j]){
                cur=1;
                res=max(res,cur);
                lcs(s1,s2,i+1,j+1,n,m,true);
            }
            else{
                 cur=0;
                 lcs(s1,s2,i+1,j,n,m,false);
                 lcs(s1,s2,i,j+1,n,m,false);
            }
        }
    }
    int longestCommonSubstr (string s1, string s2, int n, int m)
    {
        lcs(s1,s2,0,0,n,m,false);
        return res;
    }
*/
int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n, m; cin >> n >> m;
        string s1, s2;
        cin >> s1 >> s2;

        cout << longestCommonSubString (s1, s2, n, m) << endl;
    }
}