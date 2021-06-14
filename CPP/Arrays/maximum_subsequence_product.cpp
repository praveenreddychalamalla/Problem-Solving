/**
 * @author Praveen Reddy Chalamalla
 * @create date 2021-05-26
 * @desc Maximum subsequence product in an array
 */
#include <bits/stdc++.h>
using namespace std;

//O(nlogn)
long long maxProductSubsequenceOfSizeK(int a[], int n, int k) { 
	long long prod=1,prod1,prod2;
	int cnt=0,i,j;
	sort(a,a+n);
	for(i=0;i<n;i++)
		if(a[i]>0)cnt++;   //Count if there is any positive element.
	i=0;j=n-1;
	if(k%2){
		if(cnt==0){ //If all elements are -ve & k is odd, return product of k largest integers (Traverse from right to left)
			while(k--)prod*=a[j--];
			return prod;
		}
		else{
			prod=a[j--]; // If k is odd & there is atleast one +ve element, assign it to prod and pick elements in pairs optimally from here on
			k--;
		}
	}
	while(k){
		prod1=a[i]*a[i+1];
		prod2=a[j]*a[j-1];
		if(prod1>prod2){ //Pick pair of elements optimally which contributes more to prod
			prod*=prod1;
			i+=2;
		}
		else{
			prod*=prod2;
			j-=2;
		}
		k-=2;
	}
	return prod;
} 
int main(){
   	int t;
    cin >> t;
    while (t--){
    	int n;
        cin>>n;
        int k;
        cin>>k;
        int a[n];
        for(int i=0;i<n;i++)
        cin>>a[i];

        cout<<maxProductSubsequenceOfSizeK(a,n,k);
        
	    cout << "\n";
	     
    }
    return 0;
}