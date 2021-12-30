/**
 * @author Praveen Reddy Chalamalla
 * @create date 2021-08-16
 * Given two sorted arrays arr1 and arr2 of size N and M respectively and an element K. 
 * The task is to find the element that would be at the k’th position of the final sorted array.
 */

//Time Complexity - O(min(log(N,M))), Space Complexity - O(1)
#include <bits/stdc++.h>
using namespace std;


int kthElement(int a[], int b[], int n, int m, int k){
    if(n>m)return kthElement(b,a,m,n,k); //Make sure you perform binary search on smaller array
    int low=max(0,k-m); //If k>m then definitely you have to pick some elements(k-m) from smaller array
    int high=min(n,k);  //If k<n then you can pick only upto k elements from smaller array 
    while(low<=high){
        int p1=(low+high)/2; //Partition on smaller array
        int p2=k-p1; //Partition on larger array (Pick upto k-p1 elements (remaining))
        int l1=p1==0?INT_MIN:a[p1-1];
        int l2=p2==0?INT_MIN:b[p2-1];
        int r1=p1==n?INT_MAX:a[p1];
        int r2=p2==m?INT_MAX:b[p2];
        if(l1<=r2 && l2<=r1)return max(l1,l2); //Desired Partition
        else if(l1>r2)high=p1-1; //eliminate right halfspace
        else low=p1+1; //eliminate left half space
    }
    return -1;
}


int main(){
	int t;
	cin>>t;
	while(t--){
		int n,m,k;
		cin>>n>>m>>k;
		int arr1[n],arr2[m];
		for(int i=0;i<n;i++)
			cin>>arr1[i];
		for(int i=0;i<m;i++)
			cin>>arr2[i];
		
        cout << kthElement(arr1, arr2, n, m, k)<<endl;
	}
    return 0;
}  