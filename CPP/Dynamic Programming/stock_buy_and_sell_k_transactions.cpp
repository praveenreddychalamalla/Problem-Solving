/**
 * @author Praveen Reddy Chalamalla
 * @create date 2021-08-30
 * @desc In the stock market, a person buys a stock and sells it on some future date.
 *       Given the stock prices of N days in an array A[ ] and a positive integer K,
 *       find out the maximum profit a person can make in at-most K transactions. 
 *       A transaction is equivalent to (buying + selling) of a stock and 
 *      new transaction can start only when the previous transaction has been completed.
 */

//Time Complexity - O(2*n*k), Space Complexity - O(2*n*k)

#include <bits/stdc++.h>
using namespace std;

vector<vector<vector<int>>>dp;

//Stock = false indicate that you don't have stock in hand. stocl = true indicates you have stock in hand

int findMaximum(int a[], int curr, int n, int k,bool stock){ 

    if(k<=0 || curr>=n)return 0;

    if(dp[stock][k][curr]!=-1)return dp[stock][k][curr];
    
    int maxVal=0;
    if(stock){ //If you have stock in hand, sell it  
        maxVal=max(maxVal,findMaximum(a,curr+1,n,k-1,false)+a[curr]);
    }
    else{  //If you don't have a stock in hand, buy it
        maxVal=max(maxVal,findMaximum(a,curr+1,n,k,true)-a[curr]);
    }

    maxVal=max(maxVal,findMaximum(a,curr+1,n,k,stock));    //Don't buy or sell on current day

    dp[stock][k][curr]=maxVal; //Memoise the result

    return maxVal;
}

int maxProfit(int k, int n, int a[]) {
    dp.resize(2,vector<vector<int>>(k+1,vector<int>(n,-1)));
    return findMaximum(a,0,n,k,false);
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> K;
        cin >> N;
        int A[N];
        for (int i = 0; i < N; i++) cin >> A[i];

        cout << maxProfit(K, N, A) << endl;
    }
    return 0;
}