/**
 * @author Praveen Reddy Chalamalla
 * @create date 2022-07-04
 * @desc Find No.of ways of filling n places with 0's and 1's such that no two 1's are adjacent. Return ans%(1e9+7)
 */

#include <bits/stdc++.h>
using namespace std;

/**
 * N = No.of places 
 * Let Tn= Xn + Yn      { Xn = No.of valid arrangements ending with 0, Yn = No.of valid arrangements ending with 1}
 *     Xn+1 = Xn + Yn   {Take all arrangements of Xn and put 0 at end, Take all arrangements of Yn ant put 0 at end} 
 *     Yn+1 = Xn        {Take all arrangements of Xn and put 1 at end, Cannot take any arrangement of Yn and put 1 ==> conflicts 2 adjacent 1's}
 *     
 *     From above Tn = Xn+1
 *                Xn+1 = Xn + Xn-1      {Yn+1 = Xn ==> Yn = Xn-1}
 *                Xn = Xn-1 + Xn-2 . Which is fibonacci sequence.
 *     Hence Tn is Fibonacci sequence shifted by 1 i.e., Tn = F(n+1)
 */


//Time Complexity - O(n), Space Complexity - O(n). Can be reduced to {O(logn), O(logn)}, {O(n),1}
int p=1e9+7;
int fibonacci(int n){
    if(n==1||n==2)return n;
    vector<long long>dp(n,0);
    dp[0]=1;
    dp[1]=2;
    for(int i=2;i<n;i++)dp[i]=(dp[i-1]+dp[i-2])%p;
    return dp[n-1];
}

int countWays(int n){
    return fibonacci(n+1);
}