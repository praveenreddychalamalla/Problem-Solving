/**
 * @author Praveen Reddy Chalamalla
 * @create date 2021-08-05
 * @desc Given a set of n elements, find the no.of ways of partitioning it .
 */

//Time Complexity - O(n^2), Space Complexity - O(n^2)
#include<bits/stdc++.h>
using namespace std;

/**
 * Bell(n)= Summation k=1 to n { S(n,k) }. Bell Traingle Approach
*/

int bellNumber(int n){
    vector<vector<int>>dp(n+1,vector<int>(n+1,0));
    dp[0][0]=1;
    for(int i=1;i<=n;i++){
        dp[i][0]=dp[i-1][i-1];
        for(int j=1;j<=i;j++){
          dp[i][j]=dp[i-1][j-1]+dp[i][j-1];
        }
    }
    return dp[n][0];
}

int main() {
  int t;
  cin>>t;
  while(t--){
      int n,k;
      cin>>n>>k;
      cout<<bellNumber(n)<<endl;
  }
  return 0;
}
