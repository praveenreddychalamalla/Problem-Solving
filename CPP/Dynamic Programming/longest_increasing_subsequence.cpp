/**
 * @author Praveen Reddy Chalamalla
 * @create date 2022-05-14
 * @desc Given an array of integers, find the length of the longest (strictly) increasing subsequence from the given array.
 */

#include<bits/stdc++.h>
using namespace std;
//Time Complexity - O(n log n), Space Complexity - O(n)
class Solution{
    public:
  
    int longestSubsequence(int n, int a[]){
       vector<int>lis;
       lis.push_back(a[0]);
       for(int i=1;i<n;i++){
           if(lis.back()<a[i])lis.push_back(a[i]);
           else {
               int index=lower_bound(lis.begin(),lis.end(),a[i])-lis.begin();
               lis[index]=a[i];
           }
       }
       return lis.size();
    }
};

/**
 * Recursive Approach - Time Complexity : O(2^n) , Space Complexity :O(n)
 * class Solution
    {
        public:
        int LIS(int i, int n, int peak, int a[]){
            if(i>=n)return 0;
            if(peak<a[i])
                return max(1+LIS(i+1,n,a[i],a),LIS(i+1,n,peak,a)); //If peak is less than a[i], then a[i] can be part of LIS ==> Explore two choices   
            else 
                return LIS(i+1,n,peak,a); //a[i] cannot be part of LIS
        }
        int longestSubsequence(int n, int a[]){
        return LIS(0,n,INT_MIN,a);
        }
    };
 * 
 *
 * Memoization of above recursive approach - Time Complexity : O(n^2), Space Complexity : O(n^2) {Bound the value of peak by using index and use coordinate shift to handle -1 for index}
 * class Solution
    {
        public:
        int dp[n][n+1];
        int LIS(int i, int n, int j, int a[]){ //2 Changing variables - 2 D grid
            if(i>=n)return 0;
            if(dp[i][j+1]!=-1)return dp[i][j+1];
            if(j==-1||a[j]<a[i])return dp[i][j+1]=max(1+LIS(i+1,n,i,a),LIS(i+1,n,j,a));
            else return dp[i][j+1]=LIS(i+1,n,j,a);
        }
        int longestSubsequence(int n, int a[]){
            memset(dp,-1,sizeof(dp));
            return LIS(0,n,-1,a);
        }
    };
 * 
 *
 * Tabular Method - Time Complexity : O(n^2), Space Complexity : O(n)
 * class Solution
    {
        public:
        int longestSubsequence(int n, int a[]){
        int dp[n];
        for(int i=0;i<n;i++)dp[i]=1;
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                if(a[j]<a[i])dp[i]=max(dp[i],1+dp[j]);
            }
        }      
        return *max_element(dp,dp+n);
        }
    };
 */


int main()
{
    int t,n;
    cin>>t;
    while(t--)
    {
        cin>>n;
        int a[n];
        for(int i=0;i<n;i++)cin>>a[i];
        Solution ob;
        cout << ob.longestSubsequence(n, a) << endl;
    }
}