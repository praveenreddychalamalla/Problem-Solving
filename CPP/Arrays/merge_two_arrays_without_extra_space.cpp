/**
 * @author Praveen Reddy Chalamalla
 * @create date 2021-08-16
 * @desc Given two sorted arrays arr1[] of size N and arr2[] of size M. Each array is sorted in non-decreasing order. 
 * Merge the two arrays into one sorted array in non-decreasing order without using any extra space.
 */
#include <bits/stdc++.h>
using namespace std;

//Time Complexity - O((n+m)*log(n+m)), Space Complexity - O(1)
void merge(int a[], int b[], int n, int m) {
    int i=n-1,j=0;
    while(i>=0 && j<m){
        if(a[i]>=b[j]){ //element of second array should be in first array
            swap(a[i],b[j]);
        }
        i--;
        j++;
    }
    sort(a,a+n);
    sort(b,b+m);
    
}
void merge1(int a[], int b[], int n, int m) { //O(m*n). Similar to insertion sort
    for(int i=m-1;i>=0;i--){
        int ele=a[n-1]; //Save the last element of first array
        int j=n-2;
        while(j>=0 && a[j]>b[i]){ //Search for an index in a for inserting b[i]
            a[j+1]=a[j];
            j--;
        }
        if(j!=n-2||ele>b[i]){
            a[j+1]=b[i];
            b[i]=ele;
        }
    }
    return;
	    
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, i;
        cin >> n >> m;
        int arr1[n], arr2[m];
        for (i = 0; i < n; i++) {
            cin >> arr1[i];
        }
        for (i = 0; i < m; i++) {
            cin >> arr2[i];
        }
        merge(arr1, arr2, n, m);
        for (i = 0; i < n; i++) {
            cout << arr1[i] << " ";
        }
        for (i = 0; i < m; i++) {
            cout << arr2[i] << " ";
        }
        cout << "\n";
    }
    return 0;
} 