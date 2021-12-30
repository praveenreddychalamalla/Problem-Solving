/**
 * @author Praveen Reddy Chalamalla
 * @create date 2021-12-29
 * @desc Given an array arr[] denoting heights of N towers and a positive integer K,
 *       you have to modify the height of each tower either by increasing or decreasing them by K only once.
 *       After modifying, height should be a non-negative integer. 
 *       Find out what could be the possible minimum difference of the height of shortest and longest towers after you have modified each tower.
 */

//Time Complexity - O(n * log n), Space Complexity - O(1)

#include <bits/stdc++.h>
using namespace std;

/**
 * Sort the array :
 *  
 * Pick some point (i) between 0 and n-1, increment all the heights by 'K' to the left of 'i' (exclusive) and 
 * decrement all the heights by 'K' to the right of 'i' (inclusive). 
 * 
 * This way we could minimize the difference between smallest and largest towers. If you subtract K anywhere in the left half, 
 * it might result in an even lower min value, hence a greater diff between max and min, vice versa.
 *                  
 * Arrangement : a[0]+k, a[1]+k.... a[i-1]+k,    a[i]-k, a[i+1]-k,...a[n]-k
 * 
 * At any point i: Smallest height = left value i.e., (a[0]+k) or a[i]-k (Smallest value from right half after decrementing)
 *                 Largest height = right value i.e., (a[n-1]-k) or a[i-1]+k (Largest value from left half after incrementing)
 * 
 * Check this for all possible points (:-
 */

class Solution {
  public:
    int getMinDiff(int a[], int n, int k) {
       sort(a,a+n);
       int left=a[0]+k,right=a[n-1]-k;
       int res=a[n-1]-a[0];
       for(int i=1;i<n;i++){
           if(a[i]>=k){
               int curr_min=min(left,a[i]-k);
               int curr_max=max(right,a[i-1]+k);
               res=min(res,curr_max-curr_min);
           }
       }
       return res;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> k;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.getMinDiff(arr, n, k);
        cout << ans << "\n";
    }
    return 0;
}  