/**
 * @author Praveen Reddy Chalamalla
 * @create date 2021-06-27
 * @desc Given two strings. The task is to find the length of the longest common subsequnece.
 */
#include<bits/stdc++.h>
const int mod=1e9+7;
using namespace std;


int lcs(int x, int y, string s1, string s2){
    vector<vector<int>>dp;
    for(int i=0;i<=x;i++)dp.push_back(vector<int>(y+1));
    for(int i=0;i<=x;i++)dp[i][0]=0;  //Fill First row with Zeroes for simplicity
    for(int i=0;i<=y;i++)dp[0][i]=0;  //Fill First Col with Zeroes for simplicity
    for(int i=1;i<=x;i++){
        for(int j=1;j<=y;j++){
            if(s1[i-1]==s2[j-1]){
                dp[i][j]=1+dp[i-1][j-1];
            }
            else dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
        }
    }
    return dp[x][y];
}

int main()
{
    int t,n,k,x,y;
    cin>>t;
    while(t--)
    {
        cin>>x>>y;         
        string s1,s2;
        cin>>s1>>s2;        
        cout << lcs(x, y, s1, s2) << endl;
    }
    return 0;
}