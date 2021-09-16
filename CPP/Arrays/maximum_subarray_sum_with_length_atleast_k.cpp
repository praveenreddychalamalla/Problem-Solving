/**
 * @author Praveen Reddy Chalamalla
 * @create date 2021-09-15
 * @desc Given an array and a number k, find the largest sum of the subarray containing at least k numbers. 
 *       It may be assumed that the size of array is at-least k.
 */

//Time Complexity - O(n), Space Complexity - O(1)

#include <bits/stdc++.h>
using namespace std;

long long int maxSumWithK(long long int a[], long long int n, long long int k) {
    
    long long int sum=0,res,prevKSum=0;
    int i=0;
    while(i<k){
        sum+=a[i++];
    }
    res=sum;
    prevKSum=sum;
    while(i<n){

        sum+=a[i];
        prevKSum=a[i]+prevKSum-a[i-k];

        if(sum<prevKSum){ //sum=max(sum,prevKSum) 
            sum=prevKSum; 
        }
        res=max(res,sum);
        i++;
    }
    return res;
}
int main() {
    long long int t;
    cin >> t;
    while (t--) {
        long long int n, k, i;
        cin >> n;
        long long int a[n];
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        cin >> k;
        cout << maxSumWithK(a, n, k) << endl;
    }
    return 0;
}



