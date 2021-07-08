/**
 * @author Praveen Reddy Chalamalla
 * @create date 2021-07-08
 * @desc Praveen wants to paint his dog's home that has n boards with different lengths. The length of ith board is given by arr[i] where arr[] is an array of n integers. 
 * He hired k painters for this work and each painter takes 1 unit time to paint 1 unit of the board. 
 * Find the minimum time to get this job done if all painters start together with the constraint that any painter will only paint continuous boards
 */

//Time Complexity - O(n*logm), Space Complexity- O(1)

#include <bits/stdc++.h>
using namespace std;

long long getSum(int a[],int n){
    long long res=0;
    for(int i=0;i<n;i++)res+=a[i];
    return res;
}

long long minTime(int a[], int n, int k){
    // Min no of days required = days to paint the highest board
    // Max no.of days = sum of heights of boards (If we have only 1 painter)
    long long l=*max_element(a,a+n),mid,r=getSum(a,n); 
    while(l<r){
        mid=(l+r)/2;
        long long sum=0,x=1; // x stores no.of painters required
        for(int i=0;i<n;i++){
            sum+=a[i];
            if(sum>mid){ // Allocate boards to every painter so that their sum of heights < mid. If sum exceeds mid we require one more painter
                x++;
                sum=a[i];
            }
        }
        if(x<=k) r=mid; // If painters required are less than or equal to available, then we can perform better hence search in lower halfspace, including mid.
        else l=mid+1; // Search in right halfspace, exclude the mid as with that mid value required painters are more than k
    }
    return l;
}

int main(){
	int t;
	cin>>t;
	while(t--){
		int k,n;
		cin>>k>>n;
		
		int arr[n];
		for(int i=0;i<n;i++)
		    cin>>arr[i];
		cout << minTime(arr, n, k) << endl;
	}
	return 0;
}  