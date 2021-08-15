/**
 * @author Praveen Reddy Chalamalla
 * @create date 2021-08-15
 * @desc Given an array arr[] of N positive integers. Find maximum value of |arr[i] – arr[j]| + |i – j|, (0 <= i, j <= N – 1)
 */

//Time Complexity - O(n), Space Complexity - O(n)

/**
 * Removing the mod splits the equation into 4 equations - Max{[(a[i] + i) – (a[j] + j)],[(a[i] - i)-(a[j] - j)]}  and negative versions of these.
 * Pick maximum from these 4
*/
#include <bits/stdc++.h>
using namespace std;

int maxValue(int arr[], int n) {
    int a[n],b[n],max1=INT_MIN,max2=INT_MIN,min1=INT_MAX,min2=INT_MAX;
    for(int i=0;i<n;i++){
        a[i]=arr[i]+i;
        b[i]=arr[i]-i;
        max1=max(max1,a[i]);
        min1=min(min1,a[i]);
        max2=max(max2,b[i]);
        min2=min(min2,b[i]);
    }
    return max(max(max1-min1,max2-min2),max(min1-max1,min2-max2));
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin>>N;
        
        int arr[N];
        
        for(int i=0; i<N; i++)
            cin>>arr[i];

        cout << maxValue(arr,N) << endl;
    }
    return 0;
}  