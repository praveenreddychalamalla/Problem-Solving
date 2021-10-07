/**
 * @author Praveen Reddy Chalamalla
 * @create date 2021-10-07
 * @desc Edit Distance Problem
 * 
 *  Given two strings s and t. Return the minimum number of operations required to convert s to t.
 *  The possible operations are permitted:

 *   Insert a character at any position of the string.
 *   Remove any character from the string.
 *   Replace any character from the string with any other character.
 */

#include <bits/stdc++.h>
using namespace std;

int editDistance(string s, string t) {
    int n=s.length(),m=t.length();
    vector<vector<int>>dp(n+1,vector<int>(m+1,0));
    for(int i=0;i<=n;i++)dp[i][0]=i; //only option - remove all characters from first string
    for(int j=0;j<=m;j++)dp[0][j]=j; //only option - insert all characters in first string
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(s[i-1]==t[j-1])dp[i][j]=dp[i-1][j-1];
            else dp[i][j]=1+min(dp[i-1][j-1],min(dp[i-1][j],dp[i][j-1])); //Check 3 possibilities -Replace, remove, insert respectively 
        }
    }
    return dp[n][m];
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        string s, t;
        cin >> s >> t;
        int ans = editDistance(s, t);
        cout << ans << "\n";
    }
    return 0;
}