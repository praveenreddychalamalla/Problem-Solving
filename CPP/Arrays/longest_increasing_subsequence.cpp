 /**
 * @author Praveen Reddy Chalamalla
 * @create date 2021-11-15
 * @desc Given an integer array, return the length of the longest strictly increasing subsequence.
 */

#include <bits/stdc++.h>
using namespace std;

//Time Complexity - O(n^2), Space Complexity - O(n)
int lengthOfLIS(int a[], int n) {
    vector<int>dp(n,1);
    for(int i=n-1;i>=0;i--){ 
        for(int j=i+1;j<n;j++){ 
            /** If a[j] is greater than a[i] and adding a[i] to subsequence starting at a[j], 
             *  produces a subsequence which is larger than the existing subsequence starting at a[i],
             *  update the length of subsequence starting at a[i].*/
            if(a[i]<a[j] && dp[i]<1+dp[j]){  
                dp[i]=1+dp[j];
            }
        }
    }
    return *max_element(dp.begin(),dp.end());
}



int main(){
 int  t,n,i,a[100001];
 cin>>t;
 while(t--){
    cin>>n;
    for(i=0;i<n;i++)
    cin>>a[i];
    cout<<lengthOfLIS(a, n)<<endl;
 }
      
    return 0;
} 