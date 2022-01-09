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
    for(int i=0;i<=n;i++)dp[i][0]=0; 
    for(int i=0;i<=m;i++)dp[0][i]=0; 
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
 * Recursive Approach 1 - Time Complexity : 2^(m+n)
 * class Solution {
    public:
        int lcs(string& x, string& y, int m, int n, int cnt){ 
            if(m==0||n==0)return cnt;

            if(x[m-1]==y[n-1]) {
                cnt= lcs(x,y,m-1,n-1,l+1);
            }
            cnt=max(cnt,max(lcs(x,y,m-1,n,0),lcs(x,y,m,n-1,0)));
            
            return cnt;
            
        }
        int findLength(string>& s1, string& s2) {

            int m=s1.size();
            int n=s2.size();

            return lcs(nums1,nums2,m,n,0);
        }
 *  };
 *
 * 
 * Memoization of above Recursive Approach - Time Complexity - O(min(m,n)*(m*n)) //Not feasible (Memory limit/ Time limit exceeds) 
 * 
 * class Solution {
    public:
        vector<vector<vector<int>>>dp;
        int lcs(string& x, string& y, int m, int n, int cnt){ //3 Changing variables ==> 3D grid for memoization
            if(m==0||n==0)return cnt;
            
            if(dp[m][n][cnt]!=-1)return dp[m][n][cnt];
            
            int l=cnt;
            if(x[m-1]==y[n-1]) {
                l= lcs(x,y,m-1,n-1,l+1);
            }
            l=max(l,max(lcs(x,y,m-1,n,0),lcs(x,y,m,n-1,0)));
            
            return dp[m][n][cnt]=l;
            
        }
        int findLength(string>& s1, string& s2) {

            int m=s1.size();
            int n=s2.size();

            dp.resize(m+1,vector<vector<int>>(n+1,vector<int>(min(m,n),-1)));
            fill(dp.begin(),dp.end(),vector<vector<int>>(n+1,vector<int>(min(m,n),-1)));

            return lcs(nums1,nums2,m,n,0);
        }
 *  };
 *
 * 
 * 
 * Recursive Approach 2 - Time Complexity: 2^(m+n)
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