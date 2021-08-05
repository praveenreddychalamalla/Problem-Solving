/**
 * @author Praveen Reddy Chalamalla
 * @create date 2021-08-05
 * @desc Given a set of n elements, find the no.of ways of partitioning it into k subsets
 */

//Time Complexity - O(n^2), Space Complexity - O(n^2)
#include<bits/stdc++.h>
using namespace std;
/**
 * S(n,k)=k*S(n-1,k)+S(n-1,k-1) ; nth element can go into any of the available k sets with n-1 elements or can form a new set completely (k-1 sets with n-1 elements already present)
 * 
 * int waysOfPartiton(int n,int k){
 *  if(k==1 or k==n) return 1;
 *  else return k*waysOfPartiton(n-1,k)+waysOfPartition(n-1,k-1);
 * }
*/

int waysOfPartition (int n,int k){
    vector<vector<int>>dp(n+1,vector<int>(k+1,0));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++){
            if(j==1 || i==j)dp[i][j]=1;
            else dp[i][j]=j*dp[i-1][j]+dp[i-1][j-1];
        }
    }
    return dp[n][k];
}

int main() {
  int t;
  cin>>t;
  while(t--){
      int n,k;
      cin>>n>>k;
      cout<<waysOfPartition(n,k)<<endl;
  }
  return 0;
}
