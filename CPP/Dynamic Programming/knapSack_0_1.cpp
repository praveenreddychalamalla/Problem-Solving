/**
 * @author Praveen Reddy Chalamalla
 * @create date 2021-08-28
 * @desc You are given weights and values of N items, put these items in a knapsack of capacity W to get the maximum total value in the knapsack.
 * Also given an integer W which represents knapsack capacity, 
 * find out the maximum value subset of val[] such that sum of the weights of this subset is smaller than or equal to W. 
 * You cannot break an item, either pick the complete item or don’t pick it (0-1 property).
 */


//Time Complexity - O(W*n), Space Complexity - O(W*n).

/**
 * Recursive Solution - O(2^n)
 * 
 *   int KS(int W, int wt[], int val[], int i, int n){
 *   if(W==0||i==n)  return 0;    //Bag has no capacity or Objects left are 0  
 *   if(wt[i]>W)  return  KS(W,wt,val,i+1,n);      //If the weight of current object is more than the bag capacity, ignore this object.
 *   return  max(  KS(W,wt,val,i+1,n)   ,  val[i]+ KS(W-wt[i],wt,val,i+1,n)  );        //Explore by including current object and excluding current object
 *   
 *  }
*/
#include<bits/stdc++.h>
using namespace std;

int knapSack(int W, int wt[], int val[], int n) { 
    
    vector<vector<int>>dp(n+1,vector<int>(W+1,0));
    //1st row and 1st column in dp is left with zeroes because, dp[0][0:w] - No objects in hand ==> Profit =0. dp[0:n][0] - Bag Capacity is 0 ==> Profit =0. 
    for(int i=1;i<=n;i++){ //Objects
        for(int j=1;j<=W;j++){ //Bag Capacity
            if(wt[i-1]>j) dp[i][j]=dp[i-1][j]; //If the weight of current object is more than the bag capacity, ignore this object. Consider the profit with i-1 objects in hand
            else dp[i][j]=max(dp[i-1][j-wt[i-1]]+val[i-1],dp[i-1][j]); //wt,val indices start from zero => ith object index = i-1 in wt and val
        }
    }
    return dp[n][W];
}
int main(){
    int t;
    cin>>t;
    while(t--)
    {
        //reading number of elements and weight
        int n, w;
        cin>>n>>w;
        
        int val[n];
        int wt[n];
        
        //inserting the values
        for(int i=0;i<n;i++)
            cin>>val[i];
        
        //inserting the weights
        for(int i=0;i<n;i++)
            cin>>wt[i];

        cout<<knapSack(w, wt, val, n)<<endl;
        
    }
    return 0;
} 