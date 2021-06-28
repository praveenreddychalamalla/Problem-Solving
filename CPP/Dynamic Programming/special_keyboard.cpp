/**
 * @author Praveen Reddy Chalamalla
 * @create date 2021-06-28
 * @desc Find maximum numbers of A's that can be produced by pressing keys on the special keyboard N times. 
 *       Special Keyboard keys - A, Ctrl+A, Ctrl+C, Ctrl+V.
 */

/**
 * f(n)=  n if n<=6;
 *     =  max(2*f(n-3), 3*f(n-4), 4*f(n-5), 5*f(n-6), .........(n-2)*f(1)) ; 
 *        In k*f(n-(k+1)), k indicates the use of Ctrl+V -k times, after obtaining f(n-(k+1))
 */

//Time Complexity - O(n^2), Space Complexity - O(n)
#include <bits/stdc++.h>
using namespace std;

long long int optimalKeys(int n){
    if(n<=6)return n;
    long long int dp[n+1];
    for(int i=0;i<=6;i++)dp[i]=i;
    for(int i=7;i<=n;i++){
        long long int cnt=0;
        for(int j=3;i-j>=0;j++){
            cnt=max(cnt,(j-1)*dp[i-j]);
        }
        dp[i]=cnt;
    }
    return dp[n];
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        cout<<optimalKeys(N)<<endl;
    }
    return 0;
}  