/**
 * @author Praveen Reddy Chalamalla
 * @create date 2021-08-02
 * @desc Given a binary array arr of size N and an integer M. 
 *       Find the maximum number of consecutive 1's produced by flipping at most M 0's.
 */

//Time Complexity - O(n) , Space Complexity - O(n) { Can be brought down to O(1) }
#include <bits/stdc++.h>
using namespace std;

int findZeroes(int a[], int n, int m) {
    
    int j=-1,res=0,k=0;
    vector<int>v; //Push all the indices of zeroes into a vector
    for(int i=0;i<n;i++){
        if(a[i]==0)v.push_back(i);
    }
    //j points to the left boundary of subarray(exclusive), i points to the right boundary of subarray(inclusive)
    for(int i=0;i<n;i++){
        if(a[i]==0){
            m--;
            if(m<0){ //If no.of zeroes that can be flipped are over, release one zero and shrink the subarray from left (Point j to the index right after the zero held from left)
                m++;
                j=v[k++]; 
            }
        }
        res=max(res,i-j); //No.of zeroes in (j,i] <=m  hence no.of consecutive ones produced = i-j
    }
    return res;
}  

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i, m;
        cin >> n;
        int arr[n];
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        cin >> m;
        auto ans = findZeroes(arr, n, m);
        cout << ans << "\n";
    }
    return 0;
}  