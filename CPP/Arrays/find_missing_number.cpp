/**
 * @author Praveen Reddy Chalamalla
 * @create date 2021-06-11
 * @desc Given an array of size N-1 such that it only contains distinct integers in the range of 1 to N. Find the missing element. 
 */
#include <bits/stdc++.h>
using namespace std;

//Time Complexity - O(n). You Can Use XOR method also ):-
int MissingNumber(vector<int>& a, int n) {
    for(int i=0;i<n;i++){
        //Swap until the element comes to it's right position i.e., a[i] =a[a[i]-1] only when a[i]=i+1.
        while(a[i]<=n-1 && a[i]!=a[a[i]-1]){ //Seems to be O(n^2) approach, but not! Amortized analysis turns out to be O(n)
            swap(a[i],a[a[i]-1]);
        }
    }
    for(int i=0;i<n;i++){
        if(a[i]!=i+1)return i+1;
    }
    return n;
}
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        vector<int> array(n - 1);
        for (int i = 0; i < n - 1; ++i) cin >> array[i];
        cout << MissingNumber(array, n) << "\n";
    }
    return 0;
}  