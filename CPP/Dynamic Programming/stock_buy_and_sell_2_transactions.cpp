
/**
 * @author Praveen Reddy Chalamalla
 * @create date 2021-11-10
 * @desc In the stock market, a person buys a stock and sells it on some future date.
 *       Given the stock prices of N days in an array A[ ] and a positive integer K,
 *       find out the maximum profit a person can make in at-most 2 transactions. 
 *       A transaction is equivalent to (buying + selling) of a stock and 
 *       new transaction can start only when the previous transaction has been completed.
 */

//Time Complexity - O(n), Space Complexity - O(1)

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>>dp;
int maxProfit(vector<int>& prices) {
    int n=prices.size();
    if(!n)return 0;
    int buy1=INT_MAX,buy2=INT_MAX, profit1=INT_MIN,profit2=INT_MIN;
    for(int i=0;i<n;i++){
        buy1=min(buy1,prices[i]);
        profit1=max(profit1,prices[i]-buy1);
        buy2=min(buy2,prices[i]-profit1);
        profit2=max(profit2,prices[i]-buy2);
    }
    return profit2;
}
/*  Time Complexity - O(n), Space Complexity - O(n)

    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        if(!n)return 0;

        vector<int>left(n,0),right(n,0);
        int left_min=prices[0],right_max=prices[n-1],res=0;

        for(int i=1;i<n;i++){
            left_min=min(left_min,prices[i]);
            left[i]=max(left[i-1],prices[i]-left_min);
        }

        for(int i=n-2;i>=0;i--){
            right_max=max(right_max,prices[i]);
            right[i]=max(right[i+1],right_max-prices[i]);
        }

        for(int i=0;i<n;i++)res=max(res,left[i]+right[i]);
        return res;
    }
*/
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> K;
        cin >> N;
        vector<int> A(N);
        for (int i = 0; i < N; i++) cin >> A[i];

        cout << maxProfit(A) << endl;
    }
    return 0;
}