/**
 * @author Praveen Reddy Chalamalla
 * @create date 2021-08-24
 * @desc Given an array Arr[] of N distinct integers and a range from L to R, 
 *       the task is to count the number of triplets having a sum in the range [L, R]. (Both L and R are inclusive)
 */


//Time Complexity - O(n^2), Space Complexity - O(1)

#include <bits/stdc++.h>
using namespace std;
/**
 * Range - [x,y]: If no.of triplets with sum <= y is k1 and no.of triplets with sum <= x-1 is k2. 
 * All k2 triplets are present in k1, which implies k2-k1 is the no.of triplets whose sum lies in the range [x,y]
*/
int findTripletsLessThanOrEqualToK(int a[], int n,int k){
    int cnt=0;
    for(int i=0;i<n;i++){
        int l=i+1,r=n-1,sum;
        while(l<r){
            sum=a[i]+a[l]+a[r];
            if(sum<=k){ //If a[i]+a[l]+a[r]<=sum, as array is sorted, all the numbers from l to r form the required triplets with a[i] and a[r] i.e., a[i]+a[j]+a[r] <=k for l<=j<r
                cnt+=r-l;
                l++; 
            }
            else r--; //If sum is more than k, remove larger elements
        }
    }
    return cnt;
}
int countTriplets(int a[], int n, int x, int y) { 
    sort(a,a+n);
    int cnt1=findTripletsLessThanOrEqualToK(a,n,y);
    int cnt2=findTripletsLessThanOrEqualToK(a,n,x-1);
    return cnt1-cnt2;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        int Arr[N];
        for (int i = 0; i < N; i++) cin >> Arr[i];
        int L, R;
        cin >> L >> R;
        cout << countTriplets(Arr, N, L, R) << endl;
    }
    return 0;
} 