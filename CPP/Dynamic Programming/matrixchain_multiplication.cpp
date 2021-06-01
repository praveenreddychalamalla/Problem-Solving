#include <bits/stdc++.h>
using namespace std;
//Time Comlexity - O(n^3)
int matrixMultiplication(int n, int p[])
{
    int dp[n][n],i,j,k,l,cnt;
    for(i=1;i<n;i++) dp[i][i]=0; //Cost of multiplying 1 length matrix = 0. No operations required
    
    for(l=2;l<n;l++){   // l = chain length, start computing from 2 length chain to n-1 length chain
        for(i=1;i<n-l+1;i++){ //Filling upper triangular matrix in dp
            j=i+l-1;
            dp[i][j]=INT_MAX;
            for(k=i;k<j;k++){
                cnt=dp[i][k]+dp[k+1][j]+p[i-1]*p[k]*p[j];
                dp[i][j]=min(cnt,dp[i][j]); //Store the split if required.
            }
        }
    }
    return dp[1][n-1];
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        cout<<matrixMultiplication(N, arr)<<endl;
    }
    return 0;
}  