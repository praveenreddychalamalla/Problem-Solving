/**
 * @author Praveen Reddy Chalamalla
 * @create date 2021-08-30
 * @desc You are given an array prices where prices[i] is the price of a given stock on the ith day.
 *       Find the maximum profit you can achieve. You may complete as many transactions as you like
 *       (i.e., buy one and sell one share of the stock multiple times) with the following restrictions:
 *       After you sell your stock, you cannot buy stock on the next day (i.e., cooldown one day).
 * Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).
 */

//Time Complexity - O(n), Space Complexity - O(1)
#include <bits/stdc++.h>
using namespace std;
int maxProfit(int prices[],int n) {

    int no_stock=0; //Max Profit obtained with no stock on 1st day.
    int in_hand=-prices[0]; //Max Profit obtained with stock in hand on 1st day. Cost incurred in buying
    int sold=0; //Max Profit obtained by selling stock on 1st day.
    for(int i=1;i<n;i++){
        
        int curr_no_stock=max(no_stock,sold); //current days state = no stock in hand ==> This state can be reached from previous day's "no stock" state or previous day's sold state
        int curr_in_hand=max(in_hand, no_stock-prices[i]); //current days state = stock in hand ==> This state can be reached from previous day's "in hand" state or previous day's stock state + Purchase stock today ()
        int curr_sold=in_hand+prices[i]; //current days state = stock sold today ==> This state can be reached from previous day's "in hand" state + Sell today
        
        no_stock=curr_no_stock;
        in_hand=curr_in_hand;
        sold=curr_sold;
    }
    return max(no_stock, sold); //Logical to see that we won't get maximum profit with a stock in hand, as you cannot sell it on any further day
}

/***
 * Memoisation + Recursion: 
 *  vector<int>dp;
    int findMaximum(vector<int>& prices,int curr,int n){
        if(curr>=n)return 0;

        if(dp[curr]!=-1)return dp[curr]; //If result is memoised already, return

        int maxVal=0;

        for(int i=curr+1;i<n;i++){ //Assume you bought stock on current day and try selling the current stock in coming days
            if(prices[curr]<prices[i]){ //You can sell stock on ith day
                maxVal=max(maxVal,prices[i]-prices[curr]+findMaximum(prices,i+2,n)); //If cool down is k days replace i+2 with i+k+1
            }
        }

        maxVal=max(maxVal,findMaximum(prices,curr+1,n)); //Explore without buying stock on current day
        dp[curr]=maxVal; //Memoise the result
        return maxVal;
    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        dp.resize(n+1,-1);
        return findMaximum(prices,0,n);
    }
*/

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        int A[N];
        for (int i = 0; i < N; i++) cin >> A[i];

        cout << maxProfit(A,N) << endl;
    }
    return 0;
}