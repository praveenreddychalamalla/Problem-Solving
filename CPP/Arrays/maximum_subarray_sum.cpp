/**
 * @author Praveen Reddy Chalamalla
 * @create date 2021-06-22
 * @desc Maximum subarray sum - Kadanes Algorithm 
 */
#include<bits/stdc++.h>
using namespace std;
#define ll long long;
int maxSubArraySum(int a[],int n) { //Time Complexity - O(n)
        int res=a[0],sum=a[0];
        for(int i=1;i<n;i++){
            sum=max(a[i],a[i]+sum);
            res=max(res,sum);
        }
        return res;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int arr[n];
        for (i = 0; i < n; i++) 
            cin >> arr[i];
        auto ans = maxSubArraySum(arr, n);
        cout << ans << "\n";
    }
    return 0;
} 