/**
 * @author Praveen Reddy Chalamalla
 * @create date 2021-06-26
 * @desc Given an integer N denoting the Length of a line segment. 
 *       You need to cut the line segment in such a way that the cut length of a line segment each time is either x , y or z. Here x, y, and z are integers.
 *       After performing all the cut operations, your total number of cut segments must be maximum
 */

//Time Complexity - O(n), Space Complexity - O(n)
#include<bits/stdc++.h>
using namespace std;

int maximizeTheCuts(int n, int x, int y, int z){
   vector<int>dp(n+1,-1); //Fill entire dp vector with -1 and initialize dp[0] as 0
        dp[0]=0;
        for(int l=1;l<=n;l++){ //From length 1 to n
        //Choose the value x/y/z which ever gives you the maximum segments when the length of rod == l-choosed value
            if(l-x>=0 && dp[l-x]!=-1)dp[l]=max(dp[l],1+dp[l-x]); //If dp[l-x]==-1, then rod with length l-x cannot be cut completely with the given segments, hence don't choose x
            if(l-y>=0 && dp[l-y]!=-1)dp[l]=max(dp[l],1+dp[l-y]);
            if(l-z>=0 && dp[l-z]!=-1)dp[l]=max(dp[l],1+dp[l-z]);
        }
        return dp[n]==-1?0:dp[n]; //If dp[n]==-1, then length of rod cannot be cut with the given segments, hence return 0
}

int main() {
    
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;

        int x,y,z;
        cin>>x>>y>>z;

        cout<<maximizeTheCuts(n,x,y,z)<<endl;

    }

	return 0;
}  