/**
 * @author Praveen Reddy Chalamalla
 * @create date 2022-01-05
 * @desc Rod Cutting Problem
 */

//Time Complexity - O(n^2), Space Complexity - O(n)

/* Variation : If all segments are not possible to cut (from 1 to n) i.e., restriction is imposed on the lengths of the segments that can be cut
 * Tweak Unbounded knapsack - O(n^2) space . Lenghts ~ weights. Length of rod ~ Weight of bag
 */
#include<bits/stdc++.h>
using namespace std;

/**
 * Recursive Solution:
 * class Solution{
    public:
        int cutRod(int price[], int n) {
            if(n==0)return 0;
            int x=INT_MIN;
            for(int i=1;i<=n;i++){
                x=max(x,price[i-1]+cutRod(price,n-i));
            }
            return x;
        }
    };
 * 
 *
 * Memoization :
 * class Solution{
    public:
        vector<int>dp;
        int CR(int price[], int n){
            if(n==0)return 0;
            if(dp[n]!=-1)return dp[n];
            int x=INT_MIN;
            for(int i=1;i<=n;i++){
                x=max(x,price[i-1]+CR(price,n-i));
            }
            return dp[n]=x;
        }
        int cutRod(int price[], int n) {
            dp.resize(n+1);
            fill(dp.begin(),dp.end(),-1);
            return CR(price,n);
        }
    };
 */

class Solution{
  public: 
    int cutRod(int price[], int n) {
        vector<int>dp(n+1,0);
        for(int i=1;i<=n;i++){
            int x=INT_MIN;
            for(int j=1;j<=i;j++)x=max(x,price[j-1]+dp[i-j]);
            dp[i]=x;
        }
        return dp[n];
    }
};